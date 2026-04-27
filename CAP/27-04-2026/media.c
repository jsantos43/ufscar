/*
Calcula a média de 2 conceitos de avaliação
*/

#include <stdio.h>
#include <stdbool.h>

double conceito_para_nota(char conceito) {
  switch (conceito) {
    case 'A':
    case 'a':
      return 10;
    case 'B':
    case 'b':
      return 7;
    case 'C':
    case 'c':
      return 4.5;
    case 'D':
    case 'd':
      return 2.0;
    case 'E':
    case 'e':
      return 0.5;
    default:
      return 0.0;
  }
}

char nota_para_conceito(double nota) {
  if (nota >= 9.5) return 'A';
  if (nota >= 6.5) return 'B';
  if (nota >= 3.0) return 'C';
  if (nota >= 1.5) return 'D';
  
  return 'E';
}

int main(void) {
  char conceito1, conceito2;

  // for (char index = 'A'; index <= 'Z'; index++) {
  //   printf("%c -> %.2lf\n", index, conceito_para_nota(index));
  // }

  printf("Digite os conceitos da primeira e segunda nota: ");
  scanf("%c %c", &conceito1, &conceito2);

  double nota1 = conceito_para_nota(conceito1);
  double nota2 = conceito_para_nota(conceito2);

  printf("nota1: %g | nota2: %g\n", nota1, nota2);

  double media_numerica = (nota1 + nota2) / 2.0;
  char conceito_final = nota_para_conceito(media_numerica);

  printf("%c + %c = %c\n", conceito1, conceito2, conceito_final);
  printf("%g + %g = %c\n", nota1, nota2, conceito_final);

  return 0;
}