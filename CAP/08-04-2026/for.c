#include <stdio.h>

int main() {
  for (int i = 1; i <= 10; i++) {
    printf("Valor atual de i é %d\n", i);
  }

  printf("\n\n\n");

  for (int i = 10; i >= 0; i--) {
    printf("Valor atual de i é %d\n", i);
  }

  printf("\n\n\n");

  for (int i = 0; i <= 10; i+=2) {
    printf("Valor atual de i é %d\n", i);
  }

  printf("\n\n\n");

  for (int i = 1; i <= 32; i*=2) {
    printf("Valor atual de i é %d\n", i);
  }

  printf("\n\n\n");

  int j = 10;
  for (;j < 15;) {
    j += 2;
    printf("j = %d\n", j);
  }

  for(;;) {
    printf("For ever\n");
  };

  return 0;
}
