#include <stdio.h>

int main(void) {
  int vet[] = {1, 2, 3, 4};

  // Ponteiros podem ser usados como vetor
  int *p = vet;
  printf("%d\n", p[3]);

  char texto[] = { 'a', 'e', 'i', 'o', 'u' };
  char *pc = texto;
  printf("%c %c\n", pc[2], pc[0]);

  printf("\n");

  // Aritmética de ponteiros
  p = vet; // aponta para vet[0]
  printf("%d\n", *p);
  p++;
  printf("%d\n", *p);

  char sentenca[] = "Alguma coisa aqui";
  printf("%s\n", sentenca);

  pc = sentenca; // ou seja, a letra 'A' de "Alguma coisa ..."
  printf("Letra = %c\n", *pc);

  while (*pc != '\0') {
    printf("Letra = %c\n", *pc);
    pc++;
  }

  char outra_sentenca[20];
  char *origem = sentenca;
  char *destino = outra_sentenca;

  while (*origem != '\0') {
    *destino++ = *origem++;
    // origem++;
    // destino++;
  }

  *destino = '\0';
  printf("%s - %s\n", sentenca, outra_sentenca);

  // Mais algumas contas
  // exemplo: compara v[i] com v[i + 1]
  pc = &sentenca[3];
  if (*pc == 'u') printf("\né u!");

  if (*pc > *(pc + 1))
    printf("Sim\n");
  else
    printf("Não\n");

  return 0;
}