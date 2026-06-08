#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int linhas = 25;
  int colunas = 15;
  
  // int *l[linhas];
  int **l = malloc(linhas * sizeof(int*));
  if (l == NULL) {
    perror("Alocação de linhas");
    return 1;
  }
  
  l[0] = malloc(linhas * colunas * sizeof(int));
  if (l[0] == NULL) {
    perror("Alocação de dados");
    return 1;
  }

  for (int index = 1; index < linhas; index++) {
    l[index] = &l[0][index * colunas];
  }

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      l[i][j] = i + j;
    }
  }

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%3d ", l[i][j]);
    }

    printf("\n");
  }

  free(l[0]);
  free(l);

  return 0;
}