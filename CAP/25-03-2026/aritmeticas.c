/*
Código de aula para demonstrar as expressoes aritméticas
Author: João Pedro Tomaz dos Santos
*/

#include <stdio.h>

int main(void) {
  int i = 17.9, j = 8;

  int k = i + j;
  printf("k = i + j = %d + %d = %d\n", i, j, k);

  k = i - j;
  printf("k = i - j = %d - %d = %d\n", i, j, k);

  k = i * j;
  printf("k = i * j = %d * %d = %d\n", i, j, k);

  k = i / j;
  printf("k = i / j = %d / %d = %d\n", i, j, k);

  double t = i / j;
  printf("t = i / j = %d / %d = %g\n", i, j, t);

  double i2 = 5, j2 = 2;
  double t2 = i2 / j2;
  printf("\n\n\n\n");
  printf("t2 = i2 / j2 = %d / %d = %g\n", i2, j2, t2); // ?
  printf("t2 = i2 / j2 = %g / %g = %g\n", i2, j2, t2); // OK


  return 0;
}