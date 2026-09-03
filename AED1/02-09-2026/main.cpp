#include <iostream>
#include "Fila.h"
using namespace std;

int main(void) {
  cout << std::boolalpha;

  Fila F1(5);

  F1.inserir('A');
  F1.inserir('B');
  F1.inserir('C');
  F1.inserir('D');
  F1.inserir('E');
  F1.inserir('F');

  F1.imprimir();

  cout << "Elemento: " << F1.retirar() << endl;
  cout << "Elemento: " << F1.retirar() << endl;
  
  F1.inserir('G');

  cout << "Elemento: " << F1.retirar() << endl;
  cout << "Elemento: " << F1.retirar() << endl;

  F1.imprimir();

  Fila F2(5);

  F2.inserir('E');
  F2.inserir('G');

  cout << "F1 e F2 iguais: " << Fila::iguais(&F1, &F2) << endl;

  F1.imprimir();

  F2.inserir('H');
  cout << "F1 e F2 iguais: " << Fila::iguais(&F1, &F2) << endl;

  F2.imprimir();

  return 0;
}