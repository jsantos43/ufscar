#include <iostream>
#include "Pilha.h"
using namespace std;

int main() {
  Pilha minha_pilha(10);

  std::cout << "Numero Elementos: " << minha_pilha.numero_elementos() << std::endl;

  minha_pilha.empilhar('A');
  minha_pilha.empilhar('D');
  minha_pilha.empilhar('C');
  minha_pilha.empilhar('E');

  minha_pilha.imprimir();

  std::cout << "Elemento Retirado: " << minha_pilha.desempilhar() << std::endl;

  minha_pilha.imprimir();

  std::cout << "Elemento Retirado: " << minha_pilha.desempilhar() << std::endl;

  std::cout << "Numero Elementos: " << minha_pilha.numero_elementos() << std::endl;
}