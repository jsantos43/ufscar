#include <stdio.h>
#include <stdbool.h>

bool par(int numero) {
  return numero % 2 == 0;
}

int main() {
  int numero;
  printf("Digite um número: ");
  
  scanf("%d", &numero);

  printf("%d é %s\n", numero, par(numero) ? "par" : "ímpar");
}