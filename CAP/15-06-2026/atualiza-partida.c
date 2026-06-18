#include <stdio.h>


int main(void) {
  struct partida {
    int id_partida;
    int id_jogador;
    int pontuacao;
    int duracao_minutos;
    char data[11];
  };

  char nome_arquivo[200];
  printf("Nome do arquivo: ");
  scanf("%s", nome_arquivo);
  
  FILE *arquivo = fopen(nome_arquivo, "r+");
  if (arquivo == NULL) {
    perror("Abrir arquivo");
    return 1;
  }

  struct partida partida;
  
  int numero_registro = 0; 
  printf("Digite o número do registro: ");
  scanf("%d", &numero_registro);

  fseek(arquivo, numero_registro * sizeof (struct  partida), SEEK_SET);

  fread(&partida, sizeof partida, 1, arquivo);
  printf(
    "%d - %d - %d - %d - %s\n", 
    partida.id_partida, 
    partida.id_jogador, 
    partida.pontuacao, 
    partida.duracao_minutos, 
    partida.data
  );

  // Decrescimo
  partida.pontuacao -= 20;

  // Reescrita
  fseek(arquivo, -sizeof partida, SEEK_CUR);
  fwrite(&partida, sizeof partida, 1, arquivo);

  // Confirmação de escrita
  fseek(arquivo, numero_registro * sizeof (struct  partida), SEEK_SET);
  fread(&partida, sizeof partida, 1, arquivo);
  printf(
    "%d - %d - %d - %d - %s\n", 
    partida.id_partida, 
    partida.id_jogador, 
    partida.pontuacao, 
    partida.duracao_minutos, 
    partida.data
  );

  fclose(arquivo);

  return 0;
}