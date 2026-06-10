#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PALAVRAS 5014
#define TAM_MAX 26

char palavra[TAM_MAX];
char categoria[TAM_MAX];
char letras_tentadas[TAM_MAX];
int tentativas_restantes = 6;

void printar_jogo() {
  printf("============================\n");
  printf("       JOGO DA FORCA        \n");
  printf("============================\n\n");

  const int erros = 6 - tentativas_restantes;

  printf("--------      \n");
  printf("|     |       \n");

  if (erros >= 1) {
    printf("|    ( )      \n");
  } else {
    printf("|             \n");
    
  }

  if (erros >= 2) {
    if (erros < 5) {
      printf("|     |       \n");
    }
    if (erros == 5) {
      printf("|    /|       \n");
    } else if (erros == 6) {
      printf("|    /|\\     \n");
    }
  } else {
    printf("|             \n");
  }

  if (erros >= 2 && erros < 5) {
  } else if (erros >= 2) {
  }

  if (erros >= 3) {
    printf("|     |       \n");
  } else {
    printf("|             \n");
  }

  if (erros >= 4) {
    printf("|    / \\     \n");
  } else {
    printf("|             \n");
  }
  printf("\n          ");

  for (int index = 0; index < strlen(palavra); index++) {
    bool letra_acertada = false;

    for (int index2 = 0; index2 < strlen(letras_tentadas); index2++) {
      if (letras_tentadas[index2] == palavra[index]) {
        printf("%c", palavra[index]);
        letra_acertada = true;
      }
    }

    if(!letra_acertada) {
      printf("_");
    }

    printf(" ");
  }

  printf("Dica: \n");
  printf("Letras tentadas: \n");
  printf("Tentantivas: %d/6\n", tentativas_restantes);
}

void escolher_palavra() {
  FILE *arquivo_palavras = fopen("./palavras.txt", "r");
  
  if (arquivo_palavras == NULL) {
    perror("Leitura do arquivo de palavras\n");
  }

  // Escolhe uma linha no arquivo de palavras
  const int valor_aleatorio = rand() % MAX_PALAVRAS;

  char linha[2 * TAM_MAX];
  for (int index = 0; index <= valor_aleatorio; index++) {
    fgets(linha, TAM_MAX, arquivo_palavras);
  }

  // Lê a palavra e a categoria contida na linha
  sscanf(linha, "%s %s", palavra, categoria);

  fclose(arquivo_palavras);
  printf("%s %s\n", palavra, categoria);
  printf("%d \n", strlen(palavra));
}

char pedir_letra() {
  char letra; // letra padrao

  do {
    printf("Digite um caractere válido: ");
    scanf("%c", &letra);
  } while (!isalpha(letra));

  letras_tentadas[strlen(letras_tentadas)] = toupper(letra);
}

int main(void) {
  srand(time(NULL));
  escolher_palavra();
  pedir_letra();

  printar_jogo();
}