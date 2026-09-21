#include <iostream>
#include "Vetor.h"

using namespace std;

void VetorPar(Vetor v) {
  cout << "Tamanho do Vetor: " << v.get_tamanho() << endl;

  for(int index {0}; index <= v.get_tamanho(); index++) {
    v.add(index, index * 2);
  }

  v.imprimir();
}

int main(void) {

  Vetor v1(5);

  v1.add(0, 10);
  v1.add(1, 2);
  v1.add(2, 5);
  v1.add(3, 6);
  v1.add(4, 7);
  v1.add(5, 100);

  v1.imprimir();

  int pos3{0};
  v1.get(3, pos3);
  cout << "Pos 3: " << pos3 << endl;
  cout << "Tamanho: " << v1.get_tamanho() << endl;
  
  Vetor CopiaVetor(v1);
  CopiaVetor.add(0, 13);
  CopiaVetor.add(1, 15);
  
  CopiaVetor.imprimir();
  VetorPar(v1);  
  v1.imprimir();
  
  return 0;
}