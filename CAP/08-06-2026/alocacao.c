#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *c = malloc(77 * sizeof(int)); // Solicita 77 * (int) bytes de memória

  if (c == NULL) {
    printf("Alocação de memória falhou!\n");
    return 1; // Indica que deu erro
  }

  for (int index= 0; index < 77; index++) {
    c[index] = index;
  }

  int *p = &c[12];
  *p = 144;
  p[0] = 144;
  p[1] = 169;
  p[-1] = 115;

  for (int index = 0; index < 8; index++) {
    p[index] = 200 + index;
  }

  for (int index = 0; index < 77; index++) {
    printf("%d ", c[index]);
  }

  printf("\n");

  int *outro = c;

  free(outro);
  // free(c);

  return 0;
}