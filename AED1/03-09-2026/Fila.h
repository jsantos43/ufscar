#ifndef FILA_H
#define FILA_H

#include <iostream>

struct Node {
  char elemento;
  Node* next; 
};

// typedef struct Node *NodePtr;

class Fila {
  private:
    Node* primeiro;
    Node* ultimo;
    int total_elementos;
  public:
    Fila();
    void inserir(char elemento);
    char retirar();
    bool vazia();
    void imprimir();
    static bool iguais(Fila *F1,Fila *F2);
};

#endif