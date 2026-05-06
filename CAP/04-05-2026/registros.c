#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Registro clássico
struct matricula {
    int ra;
    char nome[100];
    char curso[30];
    bool tem_bolsa;
    double valor_bolsa;
};

void apresentar_aluno(struct matricula aluno) {
  printf("%s tem RA %d\n", aluno.nome, aluno.ra);
}

int main(void) {
  struct matricula aluno;
  aluno.ra = 776698;
  strncpy(aluno.nome, "João Pedro", sizeof aluno.nome);
  strncpy(aluno.curso, "Computação", sizeof aluno.curso);
  aluno.tem_bolsa = true;
  aluno.valor_bolsa = 400.00;

  apresentar_aluno(aluno);
  printf("%s tem RA %d\n", aluno.nome, aluno.ra);
  aluno.valor_bolsa *= 1.2;
  printf("Valor da bolsa: %.2lf\n", aluno.valor_bolsa);

  struct matricula aluno2  = aluno;
  strncpy(aluno2.nome, "Pedro", sizeof aluno2.nome);
  printf("Outro aluno: %s\n", aluno2.nome);
  apresentar_aluno(aluno2);

  // Ponto em R
  struct ponto {
    char nome;
    double x, y;
  };

  struct ponto p1 = {nome: 'A', x: 1.5, y: -2.0};
  printf("Ponto %c em x %g e y %g\n", p1.nome, p1.x, p1.y);

  struct s1 {
    int i;
    double d;
  };

  struct s2 {
    int i;
    double d;
  };

  struct s1 reg1 = {i: 10, d: 1.5};
  struct s1 reg2 = {i: 20, d: 0.1};
  // reg1 = reg2; Não funciona pois são tipos diferentes

  return 0;
}