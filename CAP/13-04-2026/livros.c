/*
Calcular média de dias de empréstimos de livros
Entrada: total_livros(inteiro) e dias_emprestados(inteiro) para cada livro
Saída média de dias de livros emprestados
*/

#include <stdio.h>

// int main () {
//   int total_livros;
//   scanf("%d", &total_livros);

//   int controle = 1, total_dias_emprestados = 0;
//   while (controle <= total_livros) {
//     int dias_emprestados;
//     scanf("%d", &dias_emprestados);

//     total_dias_emprestados += dias_emprestados;
//     controle++;
//   }

//   printf("%.1lf\n", (1.0 * total_dias_emprestados/total_livros));
// }

int main () {
  int total_livros;
  scanf("%d", &total_livros);

  int total_dias_emprestados = 0;
  for(int controle = 1; controle <= total_livros; controle++) {
    int dias_emprestados;
    scanf("%d", &dias_emprestados);

    total_dias_emprestados += dias_emprestados;
  }

  printf("%.1lf\n", (1.0 * total_dias_emprestados/total_livros));
}