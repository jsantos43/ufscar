#include <stdio.h>
#include <string.h>

int main(void) {
  char formato[10];
  char comentario[256];
  
  fgets(formato, sizeof(formato), stdin);
  fgets(comentario, sizeof(comentario), stdin);

  int linhas, colunas;
  scanf("%d %d", &colunas, &linhas);

  int matriz[linhas][colunas];

  int valor_maximo;
  scanf("%d", &valor_maximo);

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  // Substitui valores >127 por 255
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if (matriz[i][j] <= 127) {
        matriz[i][j] = 0;
      }
    }
  }

  // // Divide tudo por dois
  // for (int i = 0; i < linhas; i++) {
  //   for (int j = 0; j < colunas; j++) {
  //     matriz[i][j] = matriz[i][j]/2;
  //   }
  // }

  // // Multiplica tudo por dois, limitando a 255
  // for (int i = 0; i < linhas; i++) {
  //   for (int j = 0; j < colunas; j++) {
  //     matriz[i][j] *= 2;
  //     if(matriz[i][j] > 255) matriz[i][j] = 255;
  //   }
  // }

  // Fazer a média
  // for (int index = 0; index < 4; index++) {
  //   for (int i = 1; i < linhas - 1; i++) {
  //     for (int j = 1; j < colunas - 1; j++) {
  //       matriz[i][j] = (matriz[i-1][j] + matriz[i+1][j] + matriz[i][j-1] + matriz[i][j+1] + matriz[i][j]) / 5;
  //     }
  //   }
  // }

  printf("%s", formato);
  printf("%s", comentario);
  printf("%d %d\n", colunas, linhas);
  printf("%d\n", valor_maximo);

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%d ", matriz[i][j]);
    }

    printf("\n");
  }

  return 0;
}