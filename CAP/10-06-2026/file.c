#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Abertura do arquivo
  FILE *arquivo_dados = fopen("input.txt", "r");

  if (arquivo_dados == NULL) {
    perror("Abrindo arquivo");
    return 1;
  }
  
  int soma = 0;
  int quantidade = 0;
  int valor; 
  
  // Leitura do arquivo
  while(fscanf(arquivo_dados, "%d", &valor) != EOF) {
    // printf("Valor%d: %d\n", quantidade + 1, valor);
    soma += valor;
    quantidade++;
  }

  // Fechamento do arquivo
  fclose(arquivo_dados);

  // Criando arquivo
  FILE *arquivo_saida = fopen("output.txt", "w");
  if (arquivo_saida == NULL) {
    perror("Criando o arquivo de saída");
    return 2;
  }


  fprintf(arquivo_saida, "Soma: %d\n", soma);
  fprintf(arquivo_saida, "Média: %.1lf\n", (double) soma / quantidade);

  return 0;
}