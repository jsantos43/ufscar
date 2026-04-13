/*
Verificar idade para uma atividade
Entrada: idade(inteiro)
Saída: "Permitido" ou "Não Permitido"
*/

#include <stdio.h>

int main () {
  int idade = 0;

  scanf("%d", &idade);

  if (idade >= 16) {
    printf("Permitido!");
  } else {
    printf("Não Permitido!");
  }

  return 0;
}