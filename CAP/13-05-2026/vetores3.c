#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 10

void apresentar_vetor_par(const int vetor[], int comprimento) {
  for (int index = 0; index < comprimento; index++) {
    if (vetor[index] % 2 == 0) {
      printf("%d ", vetor[index]);
    }
  }

  printf("\n");
}

int obter_pos_maior(const int vetor[], int comprimento) {
  int maior = vetor[0];
  int pos = 0;

  for (int index = 1; index < comprimento; index++) {
    if (maior < vetor[index]) {
      maior = vetor[index];
      pos = index;
    }
  }

  return pos;
}

void apresentar_vetor(const int vetor[], int comprimento) {
  for (int index = 0; index < comprimento; index++) {
    printf("%d ", vetor[index]);
  }

  printf("\n");
}

void apresentar_extremidades_trocadas(int vetor[], int comprimento) {
  int aux = vetor[0];
  vetor[0] = vetor[comprimento - 1];
  vetor[comprimento - 1] = aux;

  apresentar_vetor(vetor, comprimento);
}

bool localizar(int vetor[], int comprimento, int valor) {
  int index = 0;
  bool encontrado = false;

  while (index < comprimento && !encontrado) {
    if (vetor[index] == valor) encontrado = true;
    index++;
  }

  return encontrado;
} 

int main(void) {
  int vetor[TAMANHO];
  
  srand(1245);
  for (int index = 0; index < TAMANHO; index++) {
    vetor[index] = rand() % 100;
    printf("%d ", vetor[index]);
  }
  printf("\n");

  apresentar_vetor_par(vetor, TAMANHO);

  int posicao = obter_pos_maior(vetor, TAMANHO);
  printf("%d\n", posicao);

  apresentar_extremidades_trocadas(vetor, TAMANHO);

  printf("\n");
  bool pertinente = localizar(vetor, TAMANHO, 20);
  printf("%s\n", pertinente ? "Sim" : "Não");

  return 0;
}