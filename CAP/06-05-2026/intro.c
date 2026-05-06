#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int i;
  int idade[10]; // variável com 10 posições

  printf("idade[7] = %d\n", idade[7]);

  i = 10;
  printf("i = %d\n", i);

  idade[0] = 10; // Primeira posição do array
  idade[9] = 18; // Última posição
  printf("idade[0] = %d e idade[9] = %d\n", idade[0], idade[9]);

  idade[1] = idade[9] / idade[0];
  printf("idade[1] = %d\n", idade[1]);
  printf("idade[7] = %d\n", idade[7]);

  idade[0]++;
  idade[9]++;
  printf("idade[0] = %d e idade[9] = %d\n", idade[0], idade[9]);

  double valores[100]; // 100 valores double
  int posicao = 7;
  printf("valores[%d] = %g\n", posicao, valores[posicao]);

  valores[98] = 0.0 / 0.0;
  valores[99] = 1.0 / 0.0;
  valores[97] = valores[99] / valores[99];

  for (int index = 0; index < 100; index++) {
    printf("valores[%d] = %g\n", index, valores[index]);
  }

  printf("idade -> %zu\n", sizeof idade);
  printf("valores -> %zu\n", sizeof valores);
  printf("i -> %zu\n", sizeof i);

  bool verificacoes[5000];
  char letras[50];
  struct algo {
    int i, j;
    double c,d;
    char n[10];
  };

  struct algo lista[80];

  return 0;
}