#include <stdio.h>

void troque(int *v1, int *v2) {
  int aux = *v1;

  *v1 = *v2;
  *v2 = aux;
}

void ordene(int *n1, int *n2) {
  if (*n1 > *n2) troque(n1, n2);
} 

void dobre(int *n) {
  *n = *n * 2;
}

int main(void) {
  int i = 5;
  printf("i = %d\n", i);

  int *pi = &i;
  printf("i aponta para o valor %d\n", *pi);

  int vi[] = {5, 6, 7, 8};
  pi = &vi[2];
  printf("i aponta para para o valor %d\n", *pi);

  *pi = 100;
  printf("vi[2] = %d\n", vi[2]);

  printf("\n");
  troque(&i, pi);
  printf("i = %d\n", i);
  printf("vi[2] = %d\n", vi[2]);

  int k1 = 50, k2 = 30;

  printf("\n");
  printf("k1 = %d | k2 = %d\n", k1, k2);
  ordene(&k1, &k2);
  printf("k1 = %d | k2 = %d\n", k1, k2);
  dobre(&k2);
  printf("k1 = %d | k2 = %d\n", k1, k2);

  return 0;
}