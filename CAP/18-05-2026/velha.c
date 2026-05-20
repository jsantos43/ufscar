#include <stdio.h>
#include <stdbool.h>

struct MATRIZ_TABULEIRO {
  int i;
  int j;
};

void printar_tabuleiro(char tabuleiro[3][3]) {
  printf("\n\n\n");
  printf("====================\n");
  printf("       Velha        \n");
  printf("====================\n\n");

  for (int i = 0; i < 3; i++) {
    printf("|");
    for (int j = 0; j < 3; j++) {
      printf("%2c ", tabuleiro[i][j]);

      if (j == 2) printf("|");
    }
    printf("\n");
  }

  printf("\n");
}

struct MATRIZ_TABULEIRO pedir_jogada(int jogador, char tabuleiro[3][3]) {
  char entrada;
  bool jogada_invalida = true;
  struct MATRIZ_TABULEIRO saida;

  printar_tabuleiro(tabuleiro);
  
  do {
    printf("Jogador %d, escolha o lugar[%c]: ", jogador, jogador == 1 ? 'X' : 'O');
    scanf("\n%c", &entrada);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (entrada == tabuleiro[i][j] && entrada != 'X' && entrada != 'O') {
          jogada_invalida = false;
          saida.i = i;
          saida.j = j;
        }
      }
    }

    printar_tabuleiro(tabuleiro);

    if (jogada_invalida) {
      printf("POSICAO %c INVÁLIDA!\n", entrada);
    }  
  } while (jogada_invalida);

  return saida;
}

char verificar_ganhador(char tabuleiro[3][3]) {
  char ganhador = '-';

  // Verificar ganhador por linha
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]) {
      return tabuleiro[i][0];
    }
  }

  // Verificar ganhador por coluna
  for (int j = 0; j < 3; j++) {
    if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[2][j] == tabuleiro[0][j]) {
      return tabuleiro[0][j];
    }
  }

  // Verificar diagonal principal
  if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]) {
    return tabuleiro[0][0];
  }

  // Verificar diagonal anti-principal
  if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
    return tabuleiro[1][1];
  }

  return ganhador;
}

int main(void) {
  char tabuleiro[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
  };

  int index = 0;
  bool jogando = true;
  char ganhador = '-';


  do {
    // Pedir entrada do jogador 1
    struct MATRIZ_TABULEIRO jogadaX;
    jogadaX = pedir_jogada(1, tabuleiro);
    tabuleiro[jogadaX.i][jogadaX.j] = 'X';

    ganhador = verificar_ganhador(tabuleiro);
    if (ganhador != '-') jogando = false;

    if (jogando) {
      // Pedir entrada do jogador 2
      struct MATRIZ_TABULEIRO jogadaO;
      jogadaO = pedir_jogada(2, tabuleiro);
      tabuleiro[jogadaO.i][jogadaO.j] = 'O';

      ganhador = verificar_ganhador(tabuleiro);
      if (ganhador != '-') jogando = false;
    }
  } while (jogando);

  printar_tabuleiro(tabuleiro);

  printf("O ganhador foi %c!\n", ganhador);

  return 0;
}