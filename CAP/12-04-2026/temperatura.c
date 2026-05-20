#include <stdio.h>

int main () {
    int total_sensores = 0;
    double maior_temperatura = 0, temperatura = 0;
    
    scanf("%d", &total_sensores);
    
    for(int index = 0; index < total_sensores; index++) {
        scanf("%lf", &temperatura);
        if (temperatura > maior_temperatura) maior_temperatura = temperatura;
    }
    
    printf("%.1lf", maior_temperatura);
    
    return 0;
}