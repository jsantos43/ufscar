/*
Calcular a área aproximada de um gráfico apartir das coordenadas de dois pontos
Entrada: coordenadas de dois pontos
Saída: Valor aproximado da área do gráfico de uma função
Author: João Pedro Tomaz dos Santos

  Obtenha os valores de xA, xB, yA,
  Calcule a area por (base maior + base menor) * altura / 2
  Apresente a area
*/

#include <stdio.h>

int main() {
  double xA, xB, yA, yB;

  printf("Informe as abcissas dos pontos A e B: ");
  scanf("%lf%lf", &xA, &xB);

  printf("Informe as ordenadas dos pontos A e B: ");
  scanf("%lf%lf", &yA, &yB);

  // Área = (base maior + base menor) * altura/h
  double area = (yB + yA) * (xB - xA) / 2;

  printf("A área do gráfico desses pontos eh: %.1f\n", area);

  return 0;
}