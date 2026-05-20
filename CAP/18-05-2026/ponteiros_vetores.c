#include <stdio.h>

int main(void) {
  int vet[10] = {1, 2, 3};
  printf("vet = %p\n", vet);
  printf("&vet[0] = %p\n", &vet[0]);

  return 0;
}