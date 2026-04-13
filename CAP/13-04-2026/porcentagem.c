/*
Calcular a porcentagem de dias que a velocidade foi maior que 80
Entrada: velocidade_dia até o sentinela(-1)
Saída: porcentagem de dias que a velocidade foi maior que 80
*/

#include <stdio.h>

int main() {
  double velocidade_dia;
  scanf("%lf", &velocidade_dia);

  if (velocidade_dia != -1.0) {
    int total_dias = 0, dias_relevantes = 0;

    while (velocidade_dia != -1.0) {
      total_dias++;

      if (velocidade_dia > 80) dias_relevantes++;

      scanf("%lf", &velocidade_dia);
    }

    printf("%.2lf\n", (1.0 * dias_relevantes / total_dias));
  }

  return 0;
}