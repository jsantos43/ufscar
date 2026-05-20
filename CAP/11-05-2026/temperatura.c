#include <stdio.h>

#define TAMANHO 7

int main(void) {
  int temperaturas[TAMANHO];
  int soma = 0;

  for (int index; index < TAMANHO; index++) {
    scanf("%d", &temperaturas[index]);
  }

  for (int index; index < TAMANHO; index++) {
    if (temperaturas[index] == temperaturas[TAMANHO-1]) soma++;
  }

  printf("%d\n", soma);



  return 0;
}