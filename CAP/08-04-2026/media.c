/*
Calcular a média da turma
Entrada: a quantidade de alunos, e sequencia de notas dos alunos
Saída: a média da turma
Author: João Pedro Tomaz dos Santos
  Obtenha quantidade_alunos
  soma_notas <- 0
  Para  <- 1 até quantidade_alunos faça
    Obtenha nota_aluno
    soma_notas <- soma_notas + nota_aluno
  Fimpara
  Calcule media com soma_notas / quantidade_alunos
  Aprensente media
*/

#include <stdio.h>

int main() {
  int quantidade_alunos = 0;
  double soma_nota = 0;

  printf("Digite quantos alunos na turma: ");
  scanf("%d", &quantidade_alunos);

  for (int controle = 1; controle <= quantidade_alunos; controle++) {
    double nota_aluno = 0;

    printf("Digite a nota do aluno %d: ", controle);
    scanf("%lf", &nota_aluno);

    soma_nota += nota_aluno;
  }

  double media_turma = soma_nota / quantidade_alunos;

  printf("\nA média da turma foi %.2lf\n", media_turma);

  return 0;
}