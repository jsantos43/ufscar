#include <stdlib.h>
#include <iostream>
#include "Pilha.h"

Pilha::Pilha(int tamanho) {
  tamanho_max = tamanho;
  pilha_ptr = new char(tamanho);
  topo = -1;
}

void Pilha::imprimir() {
  std::cout << "[ ";
  for (size_t index{0}; index <= this->topo; index++) {
    std::cout << pilha_ptr[index] << " ";
  }
  std::cout << "] " << std::endl;
}

bool Pilha::empilhar(char elemento) {
  if (tamanho_max < topo + 2) {
    return false;
  }

  this->pilha_ptr[topo + 1] = elemento;
  this->topo++;

  return true;
}

char Pilha::desempilhar() {
  if (!this->vazia()) {
    char elemento = this->pilha_ptr[this->topo];
    this->topo--;

    return elemento;
  } else {
    return ' ';
  }
}

bool Pilha::vazia() {
  return this->topo == -1;
}

int Pilha::numero_elementos() {
  return topo+1;
}


