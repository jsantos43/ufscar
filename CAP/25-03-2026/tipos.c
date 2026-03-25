/*
Código de aula para demonstrar os diferentes tipos de variáveis
Author: João Pedro Tomaz dos Santos
*/

#include <stdio.h>

int main() {
  int i = 200000;
  int j = i * i;

  printf("i = %d\n", i);
  printf("j = %d\n", j);

  double d = 12.803e4;
  printf("d = %g\n", d);

  char c = 'A';
  printf("c = %c\n", c + 2);
  printf("c = %d\n", '\n');
  
  return 0;
}