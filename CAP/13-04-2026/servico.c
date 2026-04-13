/*
Calcular valor final de um serviço
Entrada: valor da compra(real)
Saída: valor final após aplicação das regras
*/

#include <stdio.h>

int main() {
  double valor;
  scanf("%ln", &valor);

  double valor_final = valor;

  if (valor >= 100.01 && valor <= 200) {
    valor_final *= 0.9;
  } else if (valor > 200) {
    valor_final *= 0.8;
  }

  printf("%.2lf", valor_final);
}