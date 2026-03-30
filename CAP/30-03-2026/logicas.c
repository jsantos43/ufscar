/*
Demonstrar Variáveis Lógicas
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
	int i = 30;
	int j = 20;

	bool resultado = i > j;
	printf("%d > %d? %s\n", i, j, resultado ? "sim" : "não");
	// printf("%zu\n", sizeof(bool));

	bool valor_verdadeiro = true;
	printf("verdadeiro = %s\n", valor_verdadeiro ? "V" : "F");

	bool valor_falso = false;
	printf("falso = %s\n", valor_falso ? "V" : "F");

	bool outro_valor_logico = !valor_falso;
	printf("%d = %d? %s\n", i, j, i == j ? "sim" : "não");
	printf("outro_valor = %s\n", outro_valor_logico ? "V" : "F");

	printf("%d igual %d? %s\n", i, j, i == j ? "sim" : "não");
	printf("%d diferente %d? %s\n", i, j, i != j ? "sim" : "não");
	printf("%d maior %d? %s\n", i,j, i > j ? "sim" : "não");
	printf("%d menor %d? %s\n", i,j, i < j ? "sim" : "não");
	printf("%d maior igual %d? %s\n", i, j, i >= j ? "sim" : "não");
	printf("%d menor igual %d? %s\n", i, j, i <= j ? "sim" : "não");

	// Zona de Perigo
  printf("errado: 0 < %d < 10? %s\n", i, 0 < i < 10 ? "sim": "não");
  printf("certo: 0 < %d < 10? %s\n", i, 0 < i && i < 10 ? "sim": "não");

	return 0;
}