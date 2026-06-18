#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_PALAVRAS 5014
#define TAM_MAX 26

typedef struct {
  char palavra[TAM_MAX];
  char categoria[TAM_MAX];
  char letras_tentadas[TAM_MAX];
  int tentativas;
  bool fim;
} jogo;


void apresentar_jogo(jogo dados) {
  printf("============================\n");
  printf("      JOGO DO ADVINHA       \n");
  printf("============================\n\n");

  printf("-->  ");

  for (int index = 0; index < strlen(dados.palavra); index++) {
    bool letra_acertada = false;

    for (int index2 = 0; index2 < strlen(dados.letras_tentadas); index2++) {
      if (dados.letras_tentadas[index2] == dados.palavra[index]) {
        printf("%c", dados.palavra[index]);
        letra_acertada = true;
      }
    }

    if(!letra_acertada) {
      printf("_");
    }

    printf(" ");
  }

  printf("\n\n");
  printf("Dica: %s\n", dados.categoria);
  printf("Letras tentadas: \n");
  printf("Tentantivas: %d/6\n", dados.tentativas);
}

void escolher_palavra(jogo *dados) {
  FILE *arquivo_palavras = fopen("./palavras.txt", "r");
  
  if (arquivo_palavras == NULL) {
    perror("Erro na leitura do arquivo de palavras\n");
  }

  // Escolhe uma linha no arquivo de palavras
  const int valor_aleatorio = rand() % MAX_PALAVRAS;

  char linha[2 * TAM_MAX];
  for (int index = 0; index <= valor_aleatorio; index++) {
    fgets(linha, TAM_MAX, arquivo_palavras);
  }

  // Lê a palavra e a categoria contida na linha
  sscanf(linha, "%s %s", dados->palavra, dados->categoria);

  fclose(arquivo_palavras);
  printf("%s %s\n", dados->palavra, dados->categoria);
  printf("%d \n", strlen(dados->palavra));
}

void pedir_letra(jogo *dados) {
  char letra; // letra padrao

  printf("\nDigite um caractere válido: ");
  scanf("%c", &letra);

  bool letra_valida = isalpha(letra);
  letra = toupper(letra);

  for (int index = 0; index <= strlen(dados->letras_tentadas); index++) {
    if (letra == dados->letras_tentadas[index]) {
      letra_valida = false;
    }
  }

  if (!letra_valida) {
    pedir_letra(dados);
    return;
  }

  bool letra_acertada = false;
  for (int index = 0; index < strlen(dados->palavra); index++) {
    if (dados->palavra[index] == letra) {
      letra_acertada = true;
    }
  }

  // Verificar caractere válido
  if (!letra_acertada) {
    dados->tentativas--;
  }

  dados->letras_tentadas[strlen(dados->letras_tentadas)] = toupper(letra);
}

bool verificar_jogo(jogo dados) {
  // Acabou por limite de tentativas
  if (dados.tentativas <= 0) return true;

  // Verificar se acertou
  int letras_acertadas = 0;
  for (int index = 0; index < strlen(dados.palavra); index++) {
    // bool letra_acertada = false;

    for (int index2 = 0; index2 < strlen(dados.letras_tentadas); index2++) {
      if (dados.palavra[index] == dados.letras_tentadas[index2]) {
        letras_acertadas++;
      }
    }
  }

  if (letras_acertadas >= strlen(dados.letras_tentadas)) return true;
  else return false;
}

bool jogando = true;

int main(void) {
  srand(time(NULL));

  jogo dados;
  dados.tentativas = 6;
  dados.fim = false;


  escolher_palavra(&dados);

  while (!dados.fim) {
    apresentar_jogo(dados);

    pedir_letra(&dados);

    dados.fim = verificar_jogo(dados);
  }
}