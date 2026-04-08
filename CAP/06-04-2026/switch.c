/*
Como funciona o switch
*/

#include <stdio.h>

int main() {
    int i = 5;

    printf("Antes\n");
    switch (i) {
        case 1:
            printf("A\n");
            printf("B\n");

            break;
        case 2:
            printf("C\n");
            printf("D\n");

            break;
        case 3:
            printf("E\n");
            printf("F\n");

            break;
        case 4:
            printf("G\n");
            printf("H\n");

            break;
        default:
            printf("NADA\n");
            // break;

       printf("I\n");
    }

    printf("Depois\n");

    return 0;
}
