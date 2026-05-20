#include <stdio.h>

int main () {
    double valor = 0;
    
    for (int index = 1; index <= 120; index++) {
        scanf("%lf", &valor);
        if (index == 40 || index == 80 || index == 120) printf("%.1lf\n", valor);        
    }
    
    return 0;
}