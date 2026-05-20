#include <stdio.h>

#define TOTAL_LIVROS 40

int main() {
  int atraso_livro[TOTAL_LIVROS];
  int atraso_total = 0, maior_atraso = 0;
  
  for (int index = 0; index < TOTAL_LIVROS; index++) {
    scanf("%d", &atraso_livro[index]);
    
    atraso_total += atraso_livro[index];
    
    if (atraso_livro[index] > maior_atraso) {
      maior_atraso = atraso_livro[index];
    }
  }

  double atraso_medio = (double) atraso_total / TOTAL_LIVROS;
  int livos_acima_media = 0, total_atraso_maximo = 0;

  for(int index = 0; index < TOTAL_LIVROS; index++) {
    if (atraso_livro[index] > atraso_medio) {
      livos_acima_media++;
    }

    if (atraso_livro[index] == maior_atraso) {
      total_atraso_maximo++;
    }
  }

  printf("%d %d %d\n", livos_acima_media, atraso_total, total_atraso_maximo);


}