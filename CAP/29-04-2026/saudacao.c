#include <stdio.h>
#include <string.h>

void saudar(char* nome) {
  printf("Olá, %s!\n", nome);
  printf("Seu nome tem %d letras\n\n", strlen(nome));
}

int main() {
  char nome1[] = "Joao";
  char nome2[] = "Pedro";

  saudar(nome1);
  saudar(nome2);

  return 0;
}