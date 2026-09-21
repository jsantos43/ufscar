#ifndef LISTA_H
#define LISTA_H

struct Node {
  char dado;
  Node* next;
};

class Lista {
  private:
    Node* primeiro;
    Node* atual;
  public:
    Lista();
    bool existe(char);
    bool inserir(char);
    bool remover(char);
    bool vazia();
    bool ler_primeiro(char &);
    bool ler_proximo(char &);
};

#endif