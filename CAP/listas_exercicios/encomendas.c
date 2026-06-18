/*
Programa para ler dados gerais das entregas e situações das encomendas
Entrada: número de encomendas(inteiro), e N registros encomendas
Saída: Situação de cada entrega e quantidade total de encomendas na situação 1, 2 e 3, e velocidade média geral das entregas
*/

#include <stdio.h>
#include <string.h>

/*
Registro para guardar as informações de uma encomenda
dois números reais, distancia e tempo da entrega
um inteiro que indica as situação da encomenda
*/
struct encomenda {
    double distancia;
    double tempo;
    int situacao;
};

/*
Função para ler uma encomenda
Entrada: distancia(real), tempo(real) e situação(1, 2 ou 3)
Saída: retorna um registro do tipo encomenda
*/
struct encomenda ler_encomenda() {
    struct encomenda nova_encomenda;
    
    scanf(
        "%lf %lf %d",
        &nova_encomenda.distancia,
        &nova_encomenda.tempo,
        &nova_encomenda.situacao
    );
    
    return nova_encomenda;
}

/*
Procedimento para classificar uma entrega
Entrada: um registro da encomenda, indicie da encomenda(inteiro)
Saída: classificação da entrega(string)
*/
void classificar_entrega(struct encomenda encomenda, int ordem) {
    double velocidade_media = encomenda.distancia / encomenda.tempo;
    
    char classificacao[20];
    
    if (velocidade_media < 40) {
        strncpy(classificacao, "LENTA", 6);
    } else if (velocidade_media >= 40 && velocidade_media < 70) {
        strncpy(classificacao, "NORMAL", 7);
    } else {
        strncpy(classificacao, "RAPIDA", 7);
    }
    
    printf("Entrega %d: %s\n", ordem, classificacao);
}

/*
Procedimento para contabilizar o total de situações de uma mercadoria
Entrada: um registro de encomenda, e 3 ponteiros para o total de cada situação de entrega
*/
void registrar_situacao(struct encomenda encomenda, int *P, int *A, int *N) {
    if (encomenda.situacao == 1) {
        *P = *P + 1;
    } else if (encomenda.situacao == 2) {
        *A = *A + 1;
    } else {
        *N = *N + 1;
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    
    struct encomenda encomendas[N];
    
    int P = 0, A = 0, I = 0;
    double soma_tempo = 0, soma_distancia = 0;
    
    for (int index = 0; index < N; index++) {
        encomendas[index] = ler_encomenda();
        
        classificar_entrega(encomendas[index], index + 1);
        
        registrar_situacao(encomendas[index], &P, &A, &I);
        
        soma_tempo += encomendas[index].tempo;
        soma_distancia += encomendas[index].distancia;
    }
    
    double V = soma_distancia / soma_tempo;
    
    printf("No prazo: %d\n", P);
    printf("Com atraso: %d\n", A);
    printf("Nao concluidas: %d\n", I);
    printf("Velocidade media geral: %.2lf", V);
    
    return 0;
}