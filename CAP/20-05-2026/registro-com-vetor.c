#include <stdio.h>

#define MAXIMO 100

struct  vetor {
  int dados[MAXIMO];
  int tamanho;
};

void escreva_vetor(struct vetor vetor) {
  printf("v = ");

  for (int index = 0; index < vetor.tamanho; index++) {
    printf("%3d ", vetor.dados[index]);
  }

  printf("\n");
}

int main(void) {
  struct vetor vet1;
  vet1.tamanho = 2;
  vet1.dados[0] = 10;
  vet1.dados[1] = 20;

  escreva_vetor(vet1);
  
  return 0;
}