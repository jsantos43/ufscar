/*
O Algoritmo deve calcular o imc
Entrada: massa em kg e altura em metros
Saída: valor do IMC
Autor: João Santos
Contexto: Aula CAP 23/03/2026
*/

#include <stdio.h>

int main() {
  double massa, altura;

  printf("Digite o valor da massa(kg) e altura(m): ");
  scanf("%lf%lf", &massa, &altura);

  double imc = massa / (altura * altura);

  printf("O valor do IMC eh: %.2lf \n", imc);

  return 0;
}