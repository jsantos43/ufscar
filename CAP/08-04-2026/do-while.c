#include <stdio.h>

int main() {
  int valor = 1;

  do {
    printf("valor = %d\n", valor);
    
    valor++;
  } while (valor <= 10);

  int mes;
  do {
    printf("Digite um mês(1 a 12): ");
    
    scanf("%d", &mes);

    if (mes < 1 || mes > 12) printf("Mês %d inválido!\n", mes);
  } while (mes < 1 || mes > 12);

  int senha_correta = 0244;
  int senha = 0, tentativas = 0;
  do {
    printf("Digite a senha: ");
    scanf("%d", &senha);

    tentativas++;

    if(senha != senha_correta) {
      printf("Senha Incorreta!\n");
    }
  } while(senha != senha_correta && tentativas < 3);
  
  if (senha == senha_correta) {
    printf("Autenticado!\n");
  } else {
    printf("Senha Bloqueada!\n");
  }

  return 0;
}