/*
Programa para ler os atendimentos de um hospital em um arquivo binário e retornar as informações gerais
Entrada: nome do arquivo(string) e o arquivo binario .dat
Saída: número de atendimentos(int), setor mais movimentado(char) e
       identificador do paciente com maior tempo de atendimento(int)
Nomes:  - João Pedro Tomaz dos Santos (858031)
        - Guilherme Do Prado Sampaio (858045)
        - Kauã Souza Siqueira (858047)
        - Erick Santos (858043)
*/

#include <stdio.h>
#include <stdbool.h>

/*
Registro para os pacientes
id(int): identificador do paciente
tempo_total(int): tempo total gasto pelo paciente nos atendimentos
*/
struct paciente {
    int id;
    int tempo_total;
};

struct paciente pacientes[50];
int contador_pacientes = 0;

/*
Procedimento para registrar um paciente novo, através das informações de um atendimento
Entrada: identificador do paciente(int) e tempo de atendimento(int)
*/
void guardar_paciente(int id_paciente, int tempo) {
    bool paciente_cadastrado = false;
    
    for (int index = 0; index < contador_pacientes; index++) {
        if (pacientes[index].id == id_paciente) {
            paciente_cadastrado = true;
            pacientes[index].tempo_total += tempo;
        }
    }
    
    if (!paciente_cadastrado) {
        struct paciente novo_paciente;
        
        novo_paciente.id = id_paciente;
        novo_paciente.tempo_total = tempo;
        
        pacientes[contador_pacientes] = novo_paciente;
        
        contador_pacientes++;
    }
}

/*
Função para obter o identificador do paciente com maior tempo de atendimento
Saída: identificador do paciente com maior tempo de atendimento
*/

int obter_maior_tempo_paciente() {
    int maior_tempo_paciente = pacientes[0].tempo_total;
    int id_paciente_maior_tempo = pacientes[0].id;
    
    for (int index = 1; index < contador_pacientes; index++) {
        if (pacientes[index].tempo_total > maior_tempo_paciente) {
            maior_tempo_paciente = pacientes[index].tempo_total;
            id_paciente_maior_tempo = pacientes[index].id;
        }
    }
    
    return id_paciente_maior_tempo;
}

int main(void) {
    /*
    Registro do atendimento
    paciente(int): número do paciente
    setor(char): letra do setor do atendimento
    tempo(int): tempo gasto no atendimento
    */
    struct atendimento {
        int paciente;
        char setor;
        int tempo;
    };
    
    char nome_arquivo[20];
    scanf("%s", nome_arquivo);
    
    FILE *arquivo = fopen(nome_arquivo, "r");
    
    if (arquivo == NULL) {
        perror("Abertura do Arquivo!");
        return 1;
    }
    
    // A até M
    int atendimentos_setores[13] = {};
    int contador_atendimentos = 0;
    
    struct atendimento novo_atendimento;
    
    while (fread(&novo_atendimento, sizeof (struct atendimento), 1, arquivo) > 0) {
        contador_atendimentos++;
        
        atendimentos_setores[novo_atendimento.setor - 65]++;
        
        guardar_paciente(novo_atendimento.paciente, novo_atendimento.tempo);
    }
    
    int maior_movimento_setor = atendimentos_setores[0];
    int setor_mais_movimentado = 0;
    
    for (int index = 1; index < 13; index++) {
        if (maior_movimento_setor < atendimentos_setores[index]) {
            maior_movimento_setor = atendimentos_setores[index];
            setor_mais_movimentado = index;
        }
    }
    
    int id_paciente_maior_tempo = obter_maior_tempo_paciente();
    
    printf("ATENDIMENTOS: %d\n", contador_atendimentos);
    printf("SETOR_MAIS_MOVIMENTADO: %c\n", setor_mais_movimentado + 65);
    printf("PACIENTE_MAIOR_TEMPO: %d", id_paciente_maior_tempo);
    
    fclose(arquivo);
    
    return 0;
}