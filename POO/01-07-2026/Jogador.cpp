#include "Jogador.h"

using std::cout;
using std::endl;
using std::string;

Jogador::Jogador() {
  vida = 100;
  exp = 0;
  energia = 100;
  vivo = true;
  max_vida = 100;
  max_energia = 100;
  nome = "Jogador";
}

Jogador::Jogador(string nome_entrada) {
  vida = 100;
  exp = 0;
  energia = 100;
  vivo = true;
  max_vida = 100;
  max_energia = 100;
  nome = nome_entrada;
}

int Jogador::get_vida() {
  return vida;
}

int Jogador::get_exp() {
  return exp;
}

int Jogador::get_energia() {
  return energia;
}

bool Jogador::get_vivo() {
  return vivo;
}

int Jogador::get_max_vida() {
  return max_vida;
}

int Jogador::get_max_energia() {
  return max_energia;
}

void Jogador::expandir_vida() {
  max_vida = 100 + exp / 10;
}

void Jogador::expandir_energia() {
  max_energia = 100 + exp / 5;
}

void Jogador::regenerar_vida() {
  if (vida + 10 >= max_vida) {
    vida = max_vida;
  } else {
    vida += 10;
  }
}

void Jogador::regenerar_energia() {
  if (energia + 10 >= max_energia) {
    energia = max_energia;
  } else {
    energia += 10;
  }
}

void Jogador::perder_vida() {
  if (vida - 10 <= 0) {
    this->morrer();
  } else {
    vida -= 10;
  }
}

void Jogador::perder_energia() {
  if (energia - 10 <= 0) {
    energia = 0;
  } else {
    energia -= 10;
  }
}

void Jogador::aumentar_exp(int quantidade) {
  exp += quantidade;

  this->expandir_vida();
  this->expandir_energia();
}

void Jogador::morrer() {
  vida = 0;
  vivo = false;
}

string Jogador::get_nome() {
  return nome;
}

void Jogador::imprimir_dados() {
  cout << "\n========================================\n";
  cout << "Nome: " << this->get_nome() << endl;
  cout << "Vida: " << this->get_vida() << "/" << this->get_max_vida() << endl;
  cout << "Energia: " << this->get_energia() << "/" << this->get_max_energia() << endl;
  cout << "Exp: " << this->get_exp() << "xp" << endl;
  cout << "Status: " << (this->get_vivo() ? "Vivo" : "Morto") << endl;
  cout << "=========================================\n";
}

