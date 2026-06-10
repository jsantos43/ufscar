#include <stdio.h>

int main(void) {
  FILE *arquivo = fopen("binarios.dat", "r");

  if (arquivo == NULL) {
    perror("Lendo arquivo binário");
    return 2;
  }

  double meudouble[2];
  int meuint = 0;

  fread(meudouble, sizeof (double), 2, arquivo);
  printf("%lf %lf\n", meudouble[0], meudouble[1]);

  fread(&meuint, sizeof meuint, 1, arquivo);
  printf("%d\n", meuint);

  fread(&meuint, sizeof meuint, 1, arquivo);
  printf("%d\n", meuint);

  fclose(arquivo);

  return 0;
}