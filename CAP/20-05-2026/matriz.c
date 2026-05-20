#include <stdio.h>

#define MAXIMO 50

/*
Leitura de dados de uma matriz
Parametros:
  - matriz: matriz TAMANHOxTAMANHO
  - linhas: linhas da matriz
  - colunas: colunas da matriz
*/
void leia_matriz(double matriz[][MAXIMO], int linhas, int colunas) {
  printf("\nLeitura de matriz %d x %d\n", linhas, colunas);

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("[%2d,%2d]: ", i, j);
      scanf("%lf", &matriz[i][j]);
    }
  }
}

/*
Escreva os dados da matriz
Parametros:
  - matriz: matriz de TAMANHOxTAMANHO
  - linhas: numero linhas da matriz
  - colunas: numero colunas da matriz
*/

void escreva_matriz(const double matriz[][MAXIMO], int linhas, int colunas) {
  printf("\nMatriz:\n");
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%4.1f", matriz[i][j]);
    }

    printf("\n");
  }
}

/*
Retorna a soma de todos os valores de uma matriz
Parametros:
  - matriz: matriz[TAMANHO][TAMANHO]
  - linhas: linhas da matriz
  - colunas: colunas da matriz
*/
double soma_matriz(const double matriz[][MAXIMO], int linhas, int colunas) {
  double soma = 0;
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      soma += matriz[i][j];
    }
  }

  return soma;
}

int main(void) {
  // Primeira matriz
  double mat1[MAXIMO][MAXIMO];
  int linhas1, colunas1;

  printf("Linhas: ");
  scanf("%d", &linhas1);
  printf("Colunas: ");
  scanf("%d", &colunas1);

  leia_matriz(mat1, linhas1, colunas1);
  escreva_matriz(mat1, linhas1, colunas1);
  double soma_mat1 = soma_matriz(mat1, linhas1, colunas1);

  printf("\nA soma da matriz1 é: %.2lf\n", soma_mat1);

  // Segunda matriz
  double mat2[MAXIMO][MAXIMO];
  int linhas2, colunas2;

  printf("Linhas: ");
  scanf("%d", &linhas2);
  printf("Colunas: ");
  scanf("%d", &colunas2);

  leia_matriz(mat2, linhas2, colunas2);
  escreva_matriz(mat2, linhas2, colunas2);
  double soma_mat2 = soma_matriz(mat2, linhas2, colunas2);

  printf("A soma da matriz2 é: %.2lf\n", soma_mat2);

  return 0;
}