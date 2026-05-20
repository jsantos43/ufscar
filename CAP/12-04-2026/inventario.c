#include <stdio.h>

int main () {
    int total_categorias = 0, total_pecas = 0, pecas = 0;
    scanf("%d", &total_categorias);
    
    for (int index = 0; index < total_categorias; index++) {
        scanf("%d", &pecas);
        total_pecas += pecas;
    }
    
    printf("%d", total_pecas);
}