#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

void apresenta_vetor(int vetor[], int comprimento) {
  for (int index = 0; index < comprimento; index++) {
    printf("%3d", vetor[index]);
  }

  printf("\n");
}

int main(void) {
  int dados[TAMANHO];
  int quantidade;

  // Zerar o vetor
  quantidade = 0;

  // Colocar 10 valores aleatórios no vetor
  for (int index = 0; index < 10; index++) {
    dados[index] = rand() % 100;
    quantidade++;
  }

  // Apresentar o vetor
  for (int index = 0; index < quantidade; index++) {
    printf("%2d ", dados[index]);
  }
  printf("\n");

  // Acrescentar mais um dado ao final
  int novo_dado = 99;
  dados[quantidade] = novo_dado;
  quantidade++;

  apresenta_vetor(dados, quantidade);

  novo_dado = 0;
  dados[quantidade] = novo_dado;
  quantidade++;

  apresenta_vetor(dados, quantidade);

  return 0;
}