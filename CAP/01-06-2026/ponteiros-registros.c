#include <stdbool.h>
#include <stdio.h>

struct registro {
    int i;
    double d;
    bool b;
};

void escreva_registro(struct registro reg) {
  printf("Registro = (i = %d, d = %g, b = %d)\n", reg.i, reg.d, reg.b);
}

void zere_tudo(struct registro *reg) {
  reg->i = 0;
  (*reg).d = 0.0;
  reg->b = false;
}

void seleciona_maximos(struct registro *r1, struct registro r2) {
  r1->i = r1->i > r2.i ? r1->i : r2.i;
  r1->d = r1->d > r2.d ? r1->d : r2.d;
  r1->b = r1->b ? r1->b : r2.b;
}

int main(void) {
  struct registro r1;

  r1.i = 10;
  r1.d = -0.5;
  r1.b = true;
  escreva_registro(r1);

  struct registro r2 = { 5, 3.14, true };
  escreva_registro(r2);

  zere_tudo(&r2);
  escreva_registro(r2);

  seleciona_maximos(&r1, r2);
  escreva_registro(r1);
  
  return 0;
}