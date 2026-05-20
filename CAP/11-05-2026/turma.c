#include <stdio.h>

#define ALUNOS 5

int main(void) {
  int notas[10] = {0};
  double nota = 0;

  for (int index = 0; index < ALUNOS; index++) {
    scanf("%lf", &nota);

    notas[(int) nota]++;
  }

  for (int index = 0; index < 10; index++) {
    printf("Total notas entre %d,0 a %d,9 é %d\n", index, index, notas[index]);
  }

  return 0;
}