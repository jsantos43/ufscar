#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 15
#define PV ;
#define ABRE (
#define FECHA )
#define imprima printf

int main(void) {
  double valores[TAMANHO] = {};

  for ABRE int index = 0; index < TAMANHO; index++ FECHA {
    valores[index] = 1.0;

    imprima("valores[%d] = %.1lf\n", index, valores[index])PV
  }

  imprima("valores[%d] = %.1lf\n", 6, valores[6]);

  // Crie um vetor de inteiros com números aleatórios
  int vet[TAMANHO];
  srand(1234);
  for (int index = 0; index < TAMANHO; index++) {
    vet[index] = rand() % 100;
  }

  for (int index = 0; index < TAMANHO; index++) {
    imprima("%d ", vet[index]);
  }

  imprima("\n");

  for (int index = 0; index < TAMANHO; index++) {
    if (vet[index] % 2 != 0) {
      imprima("%d ", vet[index]);
    } 
  }

  imprima("\n");

  for (int index = TAMANHO - 1; 0 <= index; index--) {
    imprima("%d ", vet[index]);
  }

  imprima("\n");

  for (int index = 0; index < TAMANHO; index++) {
    if (index % 2 == 0) printf("%d ", vet[index]);
  }

  printf("\n");

  for (int index = 0; index < TAMANHO; index++) {
    if (vet[index] % 5 == 0) vet[index] = 0;

    printf("%d ", vet[index]);
  }
  printf("\n");

  for (int index = 0; index < TAMANHO; index++) {
    if (vet[index] % 3 == 0) vet[index] *= -1;

    printf("%d ", vet[index]);
  }
  printf("\n");

  int soma = 0;
  for (int index = 0; index < TAMANHO; index++) {
    soma += vet[index];
  }
  printf("%d\n", soma);

  printf("%g\n", 1.0 * soma / TAMANHO );

  int maiores_30 = 0;
  for (int index = 0; index < TAMANHO; index++) {
    if(vet[index] > 30) maiores_30++;
  }
  printf("%d\n", maiores_30);

  int intermediario = vet[0];
  vet[0] = vet[TAMANHO - 1];
  vet[TAMANHO - 1] = intermediario;

  printf("%d e %d\n", vet[0], vet[TAMANHO - 1]);


  return 0;
}