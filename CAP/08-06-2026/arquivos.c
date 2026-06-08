#include <stdio.h>

int main(void) {
  // Entrada
  FILE *dados;
  dados = fopen("data.txt", "r");

  if (dados == NULL) {
    perror("Acesso aos dados");
    return 1;
  }

  // Saída
  FILE *saida = fopen("saida.txt", "w");
  if (saida == NULL) {
    perror("Problemas com a saída");
    return 2;
  }

  int i1;
  fscanf(dados, "%d", &i1);

  int i2;
  fscanf(dados, "%d", &i2);

  double d;
  fscanf(dados, "%lf", &d);

  fprintf(saida, "%d %d %.1f", i1, i2, d);

  if (i1 > 0) {
    fprintf(saida, "\nErro!");
  }

  return 0;
}