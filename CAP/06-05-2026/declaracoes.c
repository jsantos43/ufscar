#include <stdio.h>

int main(void) {
  // declaração (valores são lixo)
  double v1[10];
  for (int index = 0; index < 10; index++) {
    printf("v1[%d] = %g\n", index, v1[index]);
  }
  printf("\n");

  double v2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  for (int index = 0; index < 5; index++) {
    printf("v2[%d] = %g\n", index, v2[index]);
  }
  printf("\n");

  double v3[5] = {1.1, 2.2, 3.3};
  for (int index = 0; index < 5; index++) {
    printf("v3[%d] = %g\n", index, v3[index]);
  }
  printf("\n");

  double v4[50] = {0.0}; // tudo zero
  for (int index = 0; index < 50; index++) {
    printf("v4[%d] = %g\n", index, v4[index]);
  }
  printf("\n");

  const double valores_monetarios[] = {
    200.0, 100.0, 50.0, 20.0, 10.00, 5.00, 2.00, // cédulas
    1.00, 0.50, 0.25, 0.10, 0.05, 0.01 //moedas
  };

  int tamanho = sizeof valores_monetarios / sizeof (valores_monetarios[0]);

  for (int index = 0; index < tamanho; index++) {
    printf("%2d: R$ %.2f\n", index, valores_monetarios[index]);
  }
  printf("\n");


  // char
  char vogais[] = {'A', 'E', 'I', 'O', 'U'};
  tamanho = sizeof vogais / sizeof (vogais[0]);

  for (int index = 0; index < tamanho; index++) {
    printf("%c ", vogais[index]);
  }
  printf("\n");
  printf("\n");

  char vogais_alternativas[] = "AEIOU"; // inclui o \0, total = 6 posições

  // vetores de strings
  int i[10];
  char nome[5][40] = {
    "eu", "tu", "ele", "nós", "e os outros"
  }; //vetor de strings
  for (int index = 0; index < 5; index++) {
    printf("%2d> %s\n", index, nome[index]);
  }
  printf("\n");

}