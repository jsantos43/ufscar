/*
Verificar aprovação do aluno apartir de duas notas
Entrada: nota1, nota2
Saída: "Aprovado" ou "Reprovado"
Author: João Pedro Tomaz dos Santos
*/

#include <stdio.h>

int main() {
  double nota1, nota2;

  printf("Digite as duas notas: ");
  scanf("%lf%lf", &nota1, &nota2);

  double media = (nota1 + nota2) / 2;

  if (media >= 6) {
    printf("Aprovado!\n");
  } else {
    printf("Reprovado!\n");
  }

  printf("A sua media eh: %.2f\n", media); 

  return 0;
}