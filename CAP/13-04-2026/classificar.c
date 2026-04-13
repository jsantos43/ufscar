/*
Classificar usuários com base na idade
Entrada: idade(inteiro)
Saída: "criança", "adolescente", "adulto" ou "idoso"
*/

#include <stdio.h>

int main () {
  int idade = 0;

  scanf("%d", &idade);

  if (idade <= 12) {
    printf("Criança");
  } else if (idade <= 17) {
    printf("Adolescente");
  } else if (idade <= 59) {
    printf("Adulto");
  } else {
    printf("Idoso");
  }
  
  return 0;
}