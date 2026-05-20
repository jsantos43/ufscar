#include <stdio.h>

#define TAMANHO 50
#define SENTINELA -2147483648 // Valor Arbritário

int main (void) {
  int vetor_sentinela[TAMANHO]; // com sentinela
  vetor_sentinela[0] = SENTINELA;

  int vetor_controlado[TAMANHO];
  int comprimento = 0;

  int dado = 0;
  printf("Dado: ");
  scanf("%d", &dado);

  int index = 0; // Rastrear posição
  while (dado != -1) {
    // Inserção de dados nos vetores
    vetor_sentinela[index] = dado;
    vetor_sentinela[index + 1] = SENTINELA;
    index++;

    vetor_controlado[comprimento] = dado;
    comprimento++;

    printf("Dado: ");
    scanf("%d", &dado);
  }

  // Apresentação dos vetores lido
  index = 0;
  while(vetor_sentinela[index] != SENTINELA) {
    printf("%d ", vetor_sentinela[index]);
    index++;
  }
  printf("\n");

  printf("Com controle de comprimento\n");
  for (int index = 0; index < comprimento; index++) {
    printf("%d ", vetor_controlado[index]);
  }
  printf("\n");


  return 0;
}