#include <stdio.h>
#include <stdlib.h>

void proc(int n) {
  printf("|");

  for (int index = 0; index < n; index++)
    printf(" ");
  printf("Estou começando... (%d)\n", n);

  if (n < 10) {
    proc(n + 1);
  }

  printf("|");

  for (int index = 0; index < n; index++)
    printf(" ");
  printf("Estou terminando! (%d)\n", n);
}

void proc2(int n) {
  printf("Início de proc2 (%d)\n", n);

  if (n > 0)
    proc2(n - 1);

  printf("Fim do proc2\n");
}

int soma(int n) {
  if (n <= 0) {
    return 0;
  } else {
    return n + soma(n-1);
  }
}

int fatorial(int n) {
  if (n <= 0) {
    return 1;
  } else {
    return n * fatorial(n - 1);
  }
}

int menor(const int vetor[], int tamanho) {
  if (tamanho == 1) {  
    return vetor[0];
  } else {
    int possibilidade1 = vetor[tamanho - 1];
    int possibilidade2 = menor(vetor, tamanho - 1);

    if (possibilidade1 < possibilidade2) {
      return possibilidade1;
    } else {
      return possibilidade2;
    }
  }
}

int fibonacci(int n) {
  if (n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
 
int main(void) {
  // proc(1);
  // proc2(10);

  printf("Soma(10) = %d\n", soma(10));

  printf("Fatorial(5) = %d\n", fatorial(5));

  int vetor_teste[20];
  for (int index = 0; index < 20; index++) {
    vetor_teste[index] = rand() % 100;
    printf("%d ", vetor_teste[index]);
  }
  printf("\nmenor: %d\n", menor(vetor_teste, 20));

  for (int index = 49; index < 52; index++) {
    printf("n = %d ->> %d\n", index, fibonacci(index));
  }
 
  return 0;
}