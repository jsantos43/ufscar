#include <iostream>
#include "Lista.h"
using namespace std;

void imprimir_lista(Lista& l1) {
  char elemento = ' ';
  bool lido = l1.ler_primeiro(elemento);

  cout << "[ ";

  while(lido) {
    cout << elemento << " ";

    lido = l1.ler_proximo(elemento);
  }

  cout << "]" << endl;
}

bool listas_iguais(Lista& l1, Lista& l2) {
  char elemento1;
  char elemento2;

  bool lido1 = l1.ler_primeiro(elemento1);
  bool lido2 = l2.ler_primeiro(elemento2);


  while (lido1 == true && lido2 == true) {
    if (elemento1 != elemento2) return false;

    lido1 = l1.ler_proximo(elemento1);
    lido2 = l2.ler_proximo(elemento2);
  }

  return lido1 == lido2;
}

int main(void) {
  Lista l1;

  l1.inserir('B');
  l1.inserir('D');
  l1.inserir('A');
  l1.inserir('J');
  l1.inserir('F');

  imprimir_lista(l1);

  l1.remover('D');
  l1.remover('J');
  l1.remover('I');

  imprimir_lista(l1);

  Lista l2;

  l2.inserir('A');
  l2.inserir('B');
  l2.inserir('F');

  cout << "L1 e L2 são iguais? " << (listas_iguais(l1, l2) ? "Sim" : "Não") << endl;

  imprimir_lista(l2);

  Lista l3;

  l3.inserir('A');
  l3.inserir('B');
  l3.inserir('F');
  l3.inserir('F');
  l3.inserir('C');

  imprimir_lista(l3);

  cout << "L1 e L3 são iguais? " << (listas_iguais(l1, l3) ? "Sim" : "Não") << endl;

  return 0;
}