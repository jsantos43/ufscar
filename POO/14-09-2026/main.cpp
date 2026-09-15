#include <iostream>
#include "Aluno.h"
using namespace std;

int main(void) {
  const Aluno exemplar("João");
  
  cout << "Nome: " << exemplar.get_nome() << endl;
  cout << "RA: " << exemplar.get_ra() << endl;
  
  cout << endl;

  Aluno teste("LF");

  teste.set_nome("Luizão");
  
  cout << "Nome: " << teste.get_nome() << endl;
  cout << "RA: " << teste.get_ra() << endl;

  cout << endl << "Total de Alunos: " << Aluno::get_contador() << endl;

  return 0;
}