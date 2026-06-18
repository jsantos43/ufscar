#include <stdio.h>

int main(void) {
  struct partida {
    int id_partida;
    int id_jogador;
    int pontuacao;
    int duracao_minutos;
    char data[11];
  };

  struct partida partida;

  char nome_arquivo[200];
  printf("Nome do arquivo: ");
  scanf("%s", nome_arquivo);

  FILE *arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL) {
    perror("Abrir arquivo");
    return 1;
  }

  int numero_registro = 0; 
  
  printf("Digite o número do registro: ");
  scanf("%d", &numero_registro);
  
  while (numero_registro != -1) {
    int posicao = numero_registro * sizeof(struct partida);
    printf("byte: %d\n", ftell(arquivo));
  
    fseek(arquivo, posicao, SEEK_SET);
    fread(&partida, sizeof partida, 1, arquivo);
  
    printf("Partida %d tem duração %d\n", partida.id_partida, partida.duracao_minutos);

    printf("Digite o número do registro: ");
    scanf("%d", &numero_registro);
  }

  fclose(arquivo);

  return 0;
}