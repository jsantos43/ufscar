#include <stdio.h>

int main(void) {
  int quantidade_notas;
  
  printf("Digite o total de notas: ");
  scanf("%d", &quantidade_notas);

  double notas[quantidade_notas];

  for (int index = 0; index < quantidade_notas; index++) {
    scanf("%lf", &notas[index]);
  }

  double soma = 0;
  for (int index = 0; index < quantidade_notas; index++) {
    soma += notas[index];
  }
  double media = soma / quantidade_notas;

  int contador = 0;
  for (int index = 0; index < quantidade_notas; index++) {
    if (notas[index] > media) {
      contador++;
    }
  }

  printf("%d\n", contador);

  return 0;
}