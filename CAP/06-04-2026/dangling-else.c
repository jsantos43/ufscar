#include <stdio.h>

int main(void) {
  int i = 10;
  int j = 0;

  if(i == 0) {
    if (j == 10) {
      i = j;
    }
  } else {
    printf("i não é zero\n");
  }
}