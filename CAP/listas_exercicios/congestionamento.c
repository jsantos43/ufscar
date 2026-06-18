/*
Calcular congestionamentos locais
Entrada: linhas e colunas(inteiros) de uma matriz e o L x C inteiros que indica a quantidade de carros nos cruzamentos
Saída: total de cruzamentos congestionados
*/

#include <stdio.h>

int main(void) {
    int L, C;
    
    scanf("%d %d", &L, &C);
    
    int cruzamentos[L][C];
    
    for (int i = 0; i < L; i++){
        for (int j = 0; j < C; j++) {
            scanf("%d", &cruzamentos[i][j]);
        }
    }
    
    int total_congestionados = 0;
    
    for (int i = 0; i < L; i++){
        for (int j = 0; j < C; j++) {
            if ((cruzamentos[i][j] >  cruzamentos[i+1][j] || i == L - 1) 
                && (cruzamentos[i][j] >  cruzamentos[i-1][j] || i == 0) 
                && (cruzamentos[i][j] >  cruzamentos[i][j+1] || j == C - 1) 
                && (cruzamentos[i][j] >  cruzamentos[i][j-1] || j == 0) 
            ){
                total_congestionados++;
            }
        }
    }
    
    printf("%d\n", total_congestionados);
    
    return 0;
}