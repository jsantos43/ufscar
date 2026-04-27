#include <stdio.h>

int max(int valor1, int valor2) {
  if (valor1 >= valor2) return valor1;
  return valor2;
}


int main() {
  int valor1, valor2;

  printf("Digite dois valores inteiros: ");
  scanf("%d%d", &valor1, &valor2);

  printf("O valor máximo entre %d e %d é %d\n", valor1, valor2, max(valor1, valor2));

  return 0;
}