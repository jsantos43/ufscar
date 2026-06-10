#include <stdio.h>

int main(void) {
  FILE *arquivo = fopen("binarios.dat", "w");

  if (arquivo == NULL) {
    perror("Criando arquivo binário");
  }

  double d = -2.56;

  fwrite(&d, sizeof d, 1, arquivo);

  d = 49.3428;

  fwrite(&d, sizeof d, 1, arquivo);

  int i = -1;
  fwrite(&i, sizeof i, 1, arquivo);

  i = 5;
  fwrite(&i, sizeof i, 1, arquivo);

  fclose(arquivo);

  return 0;
}