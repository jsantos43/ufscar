#include <stdio.h>

int fatorial(int numero) {
  int resultado = 1;
  
  for (int index = 2; index <= numero; index++) {
    resultado *= index;
  }

  return resultado;
}

int main(void) {
  for (int index = 0; index <= 15; index++) {
    printf("%d! = %d\n", index, fatorial(index));
  }

  return 0;
}