/*
Apresentar mensagens de erro
*/

#include <stdio.h>

// apresente_erro: mostrar uma mensagem de erro baseado no código recebido
void apresente_erro(int erro) {
  printf("\nErro: %d\n", erro);

  switch(erro) {
    case 1:
      printf("Arquivo não encontrado\n");
      break;
    case 2:
      printf("Caminho inexistente\n");
      break;
    case 3:
      printf("Sem permissão de acesso ao arquivo\n");
      break;
    default:
      printf("Erro não conhecido\n");
  }
}

// Principal
int main(void) {
  int erro;

  for (int index = 1; index <= 4; index++) {
    apresente_erro(index);
  }

  printf("\nDigite o código do erro: ");
  scanf("%d", &erro);

  apresente_erro(erro);

  return 0;
}