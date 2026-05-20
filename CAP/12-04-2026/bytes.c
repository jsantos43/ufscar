#include <stdio.h>

int main() {
    int byte = 0, total_bytes = 0;
    
    // Primeira leitura
    scanf("%d", &byte);
    if (byte != 255) total_bytes++;
    
    while(byte != 255) {
        scanf("%d", &byte);
        if (byte != 255) total_bytes++;
    }
    
    printf("%d", total_bytes);
    
    return 0;
}