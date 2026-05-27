#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef struct {
  int tamanho;
  int dados[MAX];
} vetor;

void ler_vetor(vetor *vet) {
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &vet->tamanho);

  for (int index = 0; index < vet->tamanho; index++) {
    printf("Digite o valor do vet[%d]: ", index);
    scanf("%d", &vet->dados[index]);
  }
}

bool pertence(vetor vet, int valor) {
  for (int index = 0; index < vet.tamanho; index++) {
    if (vet.dados[index] == valor) return true;
  }

  return false;
}

void escreva_vetor(vetor vet) {
  for (int index = 0; index < vet.tamanho; index++) {
    printf("%3d", vet.dados[index]);
  }

  printf("\n\n");
}

void juntar_vetores(vetor *vet1, const vetor vet2) {
  for (int index = 0; index < vet2.tamanho; index++) {
    vet1->dados[index + vet1->tamanho] = vet2.dados[index];
  }

  vet1->tamanho += vet2.tamanho;
}

int main(void) {
  vetor vet1;
  vetor vet2;

  ler_vetor(&vet1);
  escreva_vetor(vet1);
  printf(
    "%d pertence a vet1? %s\n",
    5, 
    pertence(vet1, 5) ? "Sim" : "Não"
  );

  ler_vetor(&vet2);
  escreva_vetor(vet2);
  printf(
    "%d pertence a vet2? %s\n",
    7, 
    pertence(vet2, 7) ? "Sim" : "Não"
  );

  printf("\nVetor1 Unificado: \n");
  juntar_vetores(&vet1, vet2);
  escreva_vetor(vet1);

  return 0;
}