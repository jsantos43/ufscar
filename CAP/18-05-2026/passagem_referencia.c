#include <stdio.h>

void recebe_inteiro(int v) {
  v = v / 2 + 7;

  printf("v = %d\n", v);
}

void recebe_endereco(int *v) {
  printf("O valor é %d\n", *v);
  
  *v = 88;
  printf("O valor é %d\n", *v);
}

int main(void) {
  int n = 654;
  printf("n = %d\n", n);
  recebe_inteiro(n);
  printf("n = %d\n", n);

  recebe_endereco(&n);
  printf("n = %d\n", n);

  int i = 7;
  recebe_endereco(&i);
  printf("i = %d\n", i);

  struct s {
    int um_inteiro;
    double um_double;
  };

  struct s registro;
  recebe_endereco(&registro.um_inteiro);
  printf("registro.int = %d\n", registro.um_inteiro);

  int vet[200];
  recebe_endereco(&vet[75]);
  printf("vet[75] = %d\n", vet[75]);

  int *ponteiro = &i;
  scanf("%d", ponteiro);
  recebe_endereco(ponteiro);

  return 0;
}