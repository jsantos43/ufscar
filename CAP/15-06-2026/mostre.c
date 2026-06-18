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

  FILE *arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL) {
    perror("Abrir arquivo");
    return 1;
  }

  struct partida partida;

  int quantidade = 0;
  int mair_duracao = 0;
  int id_maior_duracao = 0;
  int soma_total = 0;
  while (fread(&partida, sizeof partida, 1, arquivo) > 0) {
    soma_total += partida.duracao_minutos;

    if (partida.duracao_minutos > mair_duracao) {
      mair_duracao = partida.duracao_minutos;
      id_maior_duracao = partida.id_partida;
    } 

    quantidade++;
  }

  double duracao_media = (double) soma_total / quantidade;

  int contador_duracoes = 0;
  rewind(arquivo);
  while (fread(&partida, sizeof partida, 1, arquivo) > 0) {
    if (partida.duracao_minutos < duracao_media) {
      contador_duracoes++;
    }
  }

  printf("Nesse arquivo há %d linhas\n", quantidade);
  printf("Nessas partidas, a maior duração foi %dmin | id: %d\n", mair_duracao, id_maior_duracao);
  printf("O tempo médio é: %.1lf\n", duracao_media);
  printf("Partidas com duração inferior à média: %d\n", contador_duracoes);

  fclose(arquivo);

  return 0;
}