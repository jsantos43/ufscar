/*
Calcular o valor de x que toca o eixo das abcissas ou se ele é ausente (Y = AX + B)
Author: João Pedro Tomaz dos Santos
Entrada: valores de A e B
Saída: x na intersecção com as abcissas, "eixo x" se a reta for as abcissas e "sem x" se reta for paralela ao eixo x 
*/

#include <stdio.h>

int main (void) {
  double A, B;

  printf("Equação da Reta: Y = AX + B\n");
  printf("Digite os valores de A e B: ");
  scanf("%lf%lf", &A, &B);

  if (A != 0) {
    double x = (-B) / A;
    
    printf("%.2lf\n", x);
  } else if (B == 0) {
    printf("Eixo X\n");
  } else {
    printf("Sem X\n");
  }

  return 0;
}