#include <stdio.h>

int main(void) {
  // Criação de uma variável double
  double d = 1.75;
  printf("d = %g\n", d);
  printf("d está no endereço %p\n", &d);

  // Guardar o valor do endereço de memória dessa variável double
  double *end_d = &d;
  printf("end_d vale %p\n", end_d);

  // Usando o endereço (ponteiro) para ver a memória
  printf("O valor guardado em %p é %g\n", end_d, *end_d);

  // Usando o ponteiro

  // Alterando o valor pelo ponteiro
  *end_d = -2.5;
  printf("O valor guardado em %p é %g\n", end_d, *end_d);

  // Efeito colateral
  printf("d = %g\n", d);

  // Novo ponteiro
  double *end2; // possui lixo
  end2 = &d; // Igual a end2 = end_d
  printf("*end = %g\n", *end2);

  *end2 = 3.212;
  printf("d = %g, *end_d = %g, *end2 = %g\n", d, *end_d, *end2);

  return 0;
}