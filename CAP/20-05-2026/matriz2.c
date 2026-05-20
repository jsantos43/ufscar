#include <stdio.h>

void escreva_matriz(int linhas, int colunas, int mat[][colunas]) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%3d ", mat[i][j]);
    }

    printf("\n");
  }

  printf("\n");
}

int main(void) {
  int m1 [2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };
  escreva_matriz(2, 3, m1);

  int m2 [3][2] = {
    {1, 1},
    {2, 2},
    {3, 3}
  };
  escreva_matriz(3, 2, m2);

  return 0;
}