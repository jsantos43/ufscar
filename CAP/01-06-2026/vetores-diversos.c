#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 1;
  while (n != 0) {
    scanf("%d", &n);

    int *vet = malloc(n * sizeof (int));
    if (vet == NULL) {
      printf("Eita que deu ruim!\n");
    } else {
      printf("Tudo certo!\n");

      for (int index = 0; index < n; index++) {
        vet[index] = index;
      }

      free(vet);
    }
  }

  return 0;
}