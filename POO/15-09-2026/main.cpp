#include <iostream>
#include "Vetor.h"

using namespace std;

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

  return 0;
}