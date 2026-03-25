/*
Trabalhar com diferentes tipos de 
*/

#include <stdio.h>

int main() {
  int inteiro;
  inteiro = 23;

  printf("inteiro = %d\n", inteiro);
  printf("inteiro usa %zu bytes\n\n", sizeof inteiro);

  double duplo;
  duplo = 3.14159265389e15;
  printf("duplo = %lf\n", duplo);
  printf("duplo usa %zu bytes\n\n", sizeof duplo);

  short int curto;
  curto = 61;
  printf("curto = %u\n", curto);
  printf("curto usa %zu bytes\n\n", sizeof curto);

  char letra;
  letra = 'K';
  printf("letra em decimal(ASCII) %d\n", letra);
  printf("letra = %c (%zu bytes)\n\n", letra, sizeof letra);

  char valor;
  valor = 253;
  printf("valor = %d\n", valor + 5);
}