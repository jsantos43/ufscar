#include <stdio.h>
#include <string.h>

int main(void) {
    char comando[10];
    int filtro_escolhido = 4; // 1: +Brilho, 2: +Contraste, 3: Metade do Brilho, 4: Borrar
    
    if (fgets(comando, sizeof(comando), stdin) == NULL) return 1;
    
    if (strncmp(comando, "P2", 2) == 0) {
        char linha_aux[100];
        
        while (fgets(linha_aux, sizeof(linha_aux), stdin)) {
            if (linha_aux[0] != '#') {
                break;
            }
        }
        
        int linha, coluna, maximo;
        sscanf(linha_aux, "%d %d", &coluna, &linha);
        if (scanf("%d", &maximo) != 1) return 1;
        
        int matriz[linha][coluna];
        
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                int elemento;
                if (scanf("%d", &elemento) == 1) {
                    if (elemento <= maximo && elemento >= 0) {
                        
                        if (filtro_escolhido == 1) {
                            int novo = elemento + 50;
                            matriz[i][j] = (novo > maximo) ? maximo : novo;
                        } 
                        else if (filtro_escolhido == 2) {
                            int novo = elemento * 2;
                            matriz[i][j] = (novo > maximo) ? maximo : novo;
                        } 
                        else if (filtro_escolhido == 3) {
                            matriz[i][j] = elemento / 2;
                        } 
                        else {
                            matriz[i][j] = elemento;
                        }
                        
                    } else {
                        matriz[i][j] = -1;
                    }
                }
            }
        }
        
        if (filtro_escolhido == 4) {
            int matriz_borrada[linha][coluna];
            
            for (int i = 0; i < linha; i++) {
                for (int j = 0; j < coluna; j++) {
                    if (i > 0 && j > 0 && i < (linha - 1) && j < (coluna - 1)) {
                        matriz_borrada[i][j] = (matriz[i][j+1] + 
                                                matriz[i+1][j] + 
                                                matriz[i-1][j] + 
                                                matriz[i][j-1] + 
                                                matriz[i][j]) / 5;
                    } else {
                        matriz_borrada[i][j] = matriz[i][j];
                    }
                }
            }
            
            for (int i = 0; i < linha; i++) {
                for (int j = 0; j < coluna; j++) {
                    matriz[i][j] = matriz_borrada[i][j];
                }
            }
        }
        
        // CORREÇÃO: O cabeçalho PGM original exige COLUNA (Largura) primeiro e LINHA (Altura) depois
        printf("P2\n");
        printf("# Imagem modificada por peaga\n");
        printf("%d %d\n", coluna, linha); 
        printf("%d\n", maximo);
        
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                printf("%d ", matriz[i][j]); 
            }
            printf("\n");
        }
    } else {
        printf("Erro: O formato nao e P2 (PGM ASCII).\n");
    }

    return 0;
}