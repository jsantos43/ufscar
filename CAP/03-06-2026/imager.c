#include <stdio.h>
#include <string.h>

typedef struct {
  int dados[1000][1000];
  int linhas, colunas;
  int maximo;
} image;

image ler_imagem() {
  char formato[10];
  char comentario[256];

  fgets(formato, sizeof(formato), stdin);
  fgets(comentario, sizeof(comentario), stdin);
  
  image imagem_lida;
  scanf("%d %d", &imagem_lida.colunas, &imagem_lida.linhas);
  scanf("%d", &imagem_lida.maximo);

  for (int i = 0; i < imagem_lida.linhas; i++) {
    for (int j = 0; j < imagem_lida.colunas; j++) {
      scanf("%d", &imagem_lida.dados[i][j]);
    }
  }

  return imagem_lida;
}

void aumentar_brilho(image *imagem) {
  // Substitui valores >127 por 255
  for (int i = 0; i < imagem->linhas; i++) {
    for (int j = 0; j < imagem->colunas; j++) {
      if (imagem->dados[i][j] > 127) {
        imagem->dados[i][j] = 255;
      }
    }
  }
}

void diminuir_brilho(image *imagem) {
  // Substitui valores menor que 127 por 0
  for (int i = 0; i < imagem->linhas; i++) {
    for (int j = 0; j < imagem->colunas; j++) {
      if (imagem->dados[i][j] < 127) {
        imagem->dados[i][j] = 0;
      }
    }
  }
}

// Divide tudo por dois
void diminuir_saturacao(image *imagem) {
  for (int i = 0; i < imagem->linhas; i++) {
    for (int j = 0; j < imagem->colunas; j++) {
      imagem->dados[i][j] = imagem->dados[i][j]/2;
    }
  }
}

// Multiplica tudo por dois, limitando a 255
void aumentar_saturacao(image *imagem) {
  for (int i = 0; i < imagem->linhas; i++) {
    for (int j = 0; j < imagem->colunas; j++) {
      imagem->dados[i][j] *= 2;
      if(imagem->dados[i][j] > 255) imagem->dados[i][j] = 255;
    }
  }
}

void mostrar_imagem(image imagem) {
  printf("%s\n", "P2");
  printf("%s\n", "#Algum comentário aqui!");
  printf("%d %d\n", imagem.colunas, imagem.linhas);
  printf("%d\n", imagem.maximo);

  for (int i = 0; i < imagem.linhas; i++) {
    for (int j = 0; j < imagem.colunas; j++) {
      printf("%d ", imagem.dados[i][j]);
    }

    printf("\n");
  }
}

void borrar(image *imagem, int fator) {
  // Fazer a média dos números em volta
  for (int index = 0; index < fator; index++) {
    for (int i = 1; i < imagem->linhas - 1; i++) {
      for (int j = 1; j < imagem->colunas - 1; j++) {
        imagem->dados[i][j] = (
          imagem->dados[i-1][j] + 
          imagem->dados[i+1][j] + 
          imagem->dados[i][j-1] + 
          imagem->dados[i][j+1] + 
          imagem->dados[i][j]
        ) / 5;
      }
    }
  }
}

int main(void) {
  image minha_imagem = ler_imagem();

  // aumentar_brilho(&minha_imagem);
  // diminuir_brilho(&minha_imagem);
  // diminuir_saturacao(&minha_imagem);
  // aumentar_saturacao(&minha_imagem);

  borrar(&minha_imagem, 50);
  
  mostrar_imagem(minha_imagem);

  return 0;
}