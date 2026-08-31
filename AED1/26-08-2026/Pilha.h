#ifndef PILHA_H
#define PILHA_H

class Pilha {
  private:
    char *pilha_ptr;
    int topo;
    int tamanho_max;
  public:
    Pilha(int);
    void imprimir();
    bool empilhar(char); 
    char desempilhar();
    int numero_elementos();
    bool vazia();
};


#endif