#include <stdio.h>

#define LINHAS 6
#define COLUNAS 12

int main(void) {
  double matriz[LINHAS][COLUNAS];

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      printf("%1.f ", matriz[i][j]);
    }

    printf("\n");
  }

  printf("\n\n");


  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      printf("%c ", matriz[i][j] == 0 ? 'S' : 'N');
    }

    printf("\n");
  }

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      matriz[i][j] = 1.0;
      printf("%1.f ", matriz[i][j]);
    }

    printf("\n");
  }

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      if (i == 2) matriz[i][j] = 8.8;
      printf("%4.1f ", matriz[i][j]);
    }

    printf("\n");
  }

  printf("\n");


  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      if (j == 1) matriz[i][j] = -0.5;
      printf("%4.1f ", matriz[i][j]);
    }

    printf("\n");
  }

  printf("\n");


  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      if (i == 1) matriz[i][j] = 3 + j;
      printf("%4.1f ", matriz[i][j]);
    }

    printf("\n");
  }

  return 0;
}