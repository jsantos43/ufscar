/*
Exemplos de várias funções
*/

#include <stdio.h>

// Retorna o dobro de um valor fornecido
double dobrar(double valor) {
  return 2 * valor;
}

// Retorna o valor absoluto de um número
double modulo(double valor) {
  if (valor < 0) return -valor;
  else return valor;
}

// Retorna o valor limitando-o ao intervalo (0,5)
int limite_valor(int numero) {
  if (numero < 0) return 0;
  else if (numero > 5) return 5;
  
  return numero;
}

// Retorna a multiplicação entre o valor1 e valo2
int multiplique(int valor1, int valor2) {
  int soma = 0;

  for (int index = 1; index <= modulo(valor2); index++) {
    soma += valor1;
  }

  return soma;
}

// Principal
int main(void) {
  double valor = 2.4;
  double dobro1 = dobrar(valor);

  printf("valor = %g | dobro1 = %g\n", valor, dobro1);

  if (dobrar(valor) < 5.0) {
    printf("é menor que 5\n");
    printf("Seu valor é %g\n", dobrar(valor));
  }

  printf("dobro é igual a soma dele mesmo: %g = %g\n", dobrar(valor), valor + valor);

  for (int index = 1; index <= 10; index++) {
    printf("%i --- %g\n", index, dobrar(index));
  }

  printf("Finalmente, o quádruplo de %g é %g\n", valor, dobrar(dobrar(valor)));

  printf("Finalmente 2: 2 * (%g + 2) = %g\n", valor, dobrar(valor + 2));

  valor = -1.2;
  while (valor <= 1.2) {
    printf("|%g| = %g\n", valor, modulo(valor));
    valor += 0.3;
  }

  for (int index = -2; index <= 8; index++) {
    printf("%d --- %d\n", index, limite_valor(index));
  }

  printf("%d * %d = %d\n", 5, 3, multiplique(5, 9));

  return 0;
}