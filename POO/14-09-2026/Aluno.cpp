#include "Aluno.h"

int Aluno::contador {0};
int Aluno::proxRA {10000};

Aluno::Aluno(std::string nome)
  :ra(proxRA++), nome(nome) {
    contador++;
}

Aluno::~Aluno() {
  contador--;
}

void Aluno::set_nome(std::string nome) {
  this->nome = nome;
}

std::string Aluno::get_nome() const {
  return this->nome;
}

int Aluno::get_ra() const {
  return this->ra;
}

int Aluno::get_contador() {
  return contador;
}