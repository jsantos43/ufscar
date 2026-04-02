/*
Apresentar valor máximo entre dois números
Entrada: dois valores
Sáida: máximo entre os valores informados
Author: João Pedro Tomaz dos Santos
*/

#include <stdio.h>

int main() {
  int numero1, numero2;

  scanf("%d%d", &numero1, &numero2);

  if (numero1 > numero2) {
    printf("%d\n", numero1);
  } else {
    printf("%d\n", numero2);
  }
  
  return 0;
}