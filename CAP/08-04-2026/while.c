#include <stdio.h>

int main() {
  int valor = 1;

  while (valor <= 5) {
    printf("valor = %d\n", valor);
    
    valor++;
  }

  int contador = 0;
  while (valor != 0){
    printf("valor(0 para parar): ");

    scanf("%d", &valor);

    contador++;
  }

  printf("Você digitou %d valores\n", contador);
  
  return 0;
}