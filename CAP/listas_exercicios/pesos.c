/*
Programa para receber uma certa quantia de pessoas e mostrar algumas informações sobre
Entrada: inteiro N que indica quantos pesos a ser lidos, e N valores reais que indicam os pesos
Saída: quantidade de encomendas, total de peso, media do pesos e quantos pesos ficaram acima da média
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);
    
    double *pesos = malloc(N * sizeof (double));
    double peso_total = 0;
    
    for (int index = 0; index < N; index++) {
        scanf("%lf", &pesos[index]);
        
        peso_total += pesos[index];
    }
    
    double media_pesos = peso_total / N;
    
    int pesos_acima_media = 0;
    for (int index = 0; index < N; index++) {
        if (pesos[index] > media_pesos) {
            pesos_acima_media++;
        }
    }
    
    printf("Quantidade: %d\n", N);
    printf("Total: %.2lf\n", peso_total);
    printf("Media: %.2lf\n", media_pesos);
    printf("Acima da media: %d\n", pesos_acima_media);
    
    free(pesos);
    
    return 0;
}