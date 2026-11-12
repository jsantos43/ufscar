#ifndef ABB_H
#define ABB_H

#include <iostream>

struct Node {
  int value;
  Node* left;
  Node* right;
};

Node* criaNode(int);
bool insere(Node*&, int);
bool existe(Node*, int);
bool vazia(Node*);
Node* busca(Node*, int);
bool remove(Node*&, int);
Node* criaRaiz();
void lista(Node*);

#endif