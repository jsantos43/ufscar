/*
Decidir acesso a um recurso baseado na idade e na posse de autorização
Entrada: idade(inteiro) e tem_autorização(0 ou 1)
Saída: "Acesso permitido" ou "Acesso negado"
*/

#include <stdio.h>

int main () {
  int idade, tem_autorizacao;

  scanf("%d%d", &idade, &tem_autorizacao);

  if (idade < 18) {
    printf("Acesso negado");
  } else {
    if (tem_autorizacao == 1) {
      printf("Acesso permitido");
    } else {
      printf("Acesso negado");
    }
  }
}