#include <iostream>
#include "ABB.h"
using namespace std;

int main(void) {
  Node* R = criaRaiz();

  insere(R, 50);
  insere(R, 28);
  insere(R, 80);
  insere(R, 12);
  insere(R, 39);
  insere(R, 96);
  insere(R, 100);
  insere(R, 130);
  insere(R, 123);

  lista(R);
  cout << endl;

  remove(R, 123);
  cout << "96 existe na árvore? " << (existe(R, 96) ? "Sim" : "Não") << endl;

  lista(R);
  cout << endl;

  return 0;
}