/*
Caixa de mercado, o qual o usuário digita um comando e chama sua respectiva função, até digitar "END"
Entranda: comando("ADD", "SELL", "REPORT", "END"), se comando é
            - "ADD": identificador do produto(inteiro), nome(string), preço(double), quantidade(inteiro)
            - "SELL": identificador do produto(inteiro), quantidade(inteiro)
Saída: se comando é
         - "ADD": "PRODUTO CADASTRADO"
         - "SELL": "PRODUTO NAO ENCONTRADO" para identificador inválido, "ESTOQUE INSUFICIENTE" para quantidade insuficiente,
                   "VENDA OK - SUBTOTAL: valor" caso dê certo
         - "REPORT": total vendido(double), produto mais vendido(string) e estoque restante(inteiro)
Alunos: - Erick Santos (858043)
        - João Pedro Tomaz dos Santos (858031)
        - Pedro Henrique Borges da Costa (858027)
        - Guilherme do Prado Sampaio (858045)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Registro de produto
struct produto {
  int identificador, quantidade, vendidos;
  char nome[20];
  double preco;
};

// array dos produtos
struct produto produtos[100];
int total_produtos_cadastros = 0;

/*
Procedimento para cadastrar um novo produto
Entranda: identificador(inteiro), nome(string), preco(double), quantidade(inteiro)
Saída: "PRODUTO CADASTRADO"
*/
void cadastrar_produto() {
  struct produto novo_produto;

  scanf("%d", &novo_produto.identificador);
  scanf("%s", novo_produto.nome);
  scanf("%lf", &novo_produto.preco);
  scanf("%d", &novo_produto.quantidade);
  novo_produto.vendidos = 0;

  produtos[total_produtos_cadastros] = novo_produto;
  total_produtos_cadastros++;

  printf("PRODUTO CADASTRADO\n");
}

/*
Procedimento para registrar quantidade de um produto vendido
Entrada: identificador do produto(inteiro) e quantidade vendida(inteiro)
Saída: "PRODUTO NAO ENCONTRADO" para identificador inválido, "ESTOQUE INSUFICIENTE" para quantidade insuficiente,
       "VENDA OK - SUBTOTAL: valor" caso dê certo
*/
void vender_produto() {
  int identificador, quantidade_vendida;
  scanf("%d %d", &identificador, &quantidade_vendida);

  // Encontar índice do produto pelo identificador fornecido
  int indicie_produto_encontrado = -1;
  for (int index = 0; index < total_produtos_cadastros; index++) {
    if(produtos[index].identificador == identificador) {
      indicie_produto_encontrado = index;
    } 
  }

  // -1 representa que o produto não foi encontrado
  if (indicie_produto_encontrado == -1) {
    printf("PRODUTO NAO ENCONTRADO\n");
    return;
  }

  struct produto produto_encontrado = produtos[indicie_produto_encontrado];
  int estoque = produto_encontrado.quantidade - produto_encontrado.vendidos;

  if (estoque < quantidade_vendida) {
    printf("ESTOQUE INSUFICIENTE\n");
    return;
  }

  // Atualizar vendidos no produto
  produtos[indicie_produto_encontrado].vendidos += quantidade_vendida;

  printf("VENDA OK - SUBTOTAL: %.2lf\n", quantidade_vendida * produto_encontrado.preco);
}

/*
Procedimento para ler o relatório de venda e estoque
Entrada: nenhuma
Saída: total vendido(double), produto mais vendido(string) e estoque restante(inteiro)
*/
void ler_relatorio() {
  double valor_total = 0;
  int estoque_restante = 0;
  int quantidade_produto_mais_vendido = 0;
  int indicie_produto_mais_vendido = -1;

  for (int index = 0; index < total_produtos_cadastros; index++) {
    valor_total += produtos[index].vendidos * produtos[index].preco;
    estoque_restante += produtos[index].quantidade - produtos[index].vendidos;

    // Veirificar se há um produto mais vendido
    if (quantidade_produto_mais_vendido < produtos[index].vendidos) {
      quantidade_produto_mais_vendido = produtos[index].vendidos;
      indicie_produto_mais_vendido = index;
    }
  }

  printf("TOTAL VENDIDO: %.2lf\n", valor_total);
  printf(
    "PRODUTO MAIS VENDIDO: %s\n", 
    indicie_produto_mais_vendido == -1 ? "NENHUM" : produtos[indicie_produto_mais_vendido].nome);
  printf("ESTOQUE RESTANTE: %d\n", estoque_restante);
}

int main(void) {
  bool fim = false;

  while(!fim) {
    char comando[10];
    scanf("%s", comando);

    if (strncmp("ADD", comando, 3) == 0) {
      cadastrar_produto();
    } else if(strncmp("SELL", comando, 4) == 0) {
      vender_produto();
    } else if (strncmp("REPORT", comando, 6) == 0) {
      ler_relatorio();
    } else if (strncmp("END", comando, 3) == 0) {
      fim = true;
    }
  };

  return 0;
}