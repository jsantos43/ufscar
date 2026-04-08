/*
Converte um conceito literal para uma nota númerica
*/

#include <stdio.h>

int main(void) {
  char conceito;

  printf("Digite o conceito: ");
  scanf("%c", &conceito);

  double valor;
  switch (conceito) {
    case 'a':
    case 'A':
      valor = 10.0;
      break;
    case 'b':
    case 'B':
      valor = 8.0;
      break;
    case 'c':
    case 'C':
      valor = 7.0;
      break;
    case 'd':
    case 'D':
      valor = 4.0;
      break;
    case 'e':
    case 'E':
      valor = 1.0;
      break;
    default:
      valor = 0.0;
  }

  printf("O conceito %c vale %.1lf\n", conceito, valor);

  return 0;
}