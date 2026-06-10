#include <stdio.h>

int main(void) {
  union {
    int i;
    unsigned char c[4];
  } dado;

  dado.i = 1;

  for (int index = 0; index < 4; index++) {
    printf("%02x ", dado.c[index]);
  }

  return 0;
}