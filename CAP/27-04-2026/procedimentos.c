/*
Apresentar exemplos de procedimentos
*/

#include <stdio.h>

void aprensetar_menu(void) {
  printf(
    "Opções:\n"
    " 1. Inserir\n"
    " 2. Remover\n"
    " 3. Listar\n"
    " 4. Limpar tudo\n"
    " 5. Enviar via email\n"
    " 6. Encaminhar email\n"
    " 0. Sair\n"
    "Digite a sua opção: "
  );
}

int main () {


  aprensetar_menu();

  int opcao;
  scanf("%d", &opcao);

  while (opcao != 0) {
    printf("\nVocê escolheu a opção: %d\n\n", opcao);

    aprensetar_menu();
    scanf("%d", &opcao);
  }
  
  printf("FIM\n");

  return 0;
}