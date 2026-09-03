#ifndef FILA_H
#define FILA_H

#include <iostream>

class Fila {
  private:
    int inicio;
    int fim;
    int total_elementos;
    int tamanho;
    char *ptr;
  public:
    Fila(int);
    bool inserir(char t = 5);
    char retirar();
    bool vazia();
    bool cheia();
    void imprimir();
    static bool iguais(Fila *F1,Fila *F2);
};

#endif