#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ALUNOS 3

struct alunos {
  char nome[80];
  int ra;
  double nota1, nota2, nota3;
};

void leia_aluno(struct alunos *aluno) {
  printf("Nome: ");
  // fgets(aluno->nome, sizeof(aluno->nome), stdin);
  scanf("%s", aluno->nome);

  printf("Número RA: ");
  scanf("%d", &aluno->ra);

  printf("Notas: ");
  scanf("%lf%lf%lf", &aluno->nota1, &aluno->nota2, &aluno->nota3);

  printf("\n");
}

void escreva_aluno(struct alunos aluno) {
  printf("-----------------------------\n");
  printf("Nome: %s", aluno.nome);
  printf("RA: %d\n", aluno.ra);
  printf("Notas: %g %g %g\n", aluno.nota1, aluno.nota2, aluno.nota3);
  printf("-----------------------------\n");
}

int main(void) {
  struct alunos aluno[26];

  for (int index = 0; index < TOTAL_ALUNOS; index++) {
    leia_aluno(&aluno[index]);
  }

  // for (int index = 0; index < TOTAL_ALUNOS; index++) {
  //   escreva_aluno(aluno[index]);
  // }

  for (int index = 0; index < TOTAL_ALUNOS; index++) {
    double media = (aluno[index].nota1 + aluno[index].nota2 + aluno[index].nota3) / 3;
    
    printf("%06d %15s ", aluno[index].ra, aluno[index].nome);
    printf("%5.1f %5.1f %5.1f", 
      aluno[index].nota1, 
      aluno[index].nota2, 
      aluno[index].nota3
    );
    printf("%5.1f\n", media);
  }
  

  return 0;
}