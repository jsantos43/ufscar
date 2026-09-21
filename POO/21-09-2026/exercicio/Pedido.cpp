#include "Pedido.h"

int Pedido::total_pedidos = 0;

Pedido::Pedido(std::string nome, int quantidade) 
  : nome(nome), quantidade(quantidade), id(total_pedidos) {

  std::string *itens = new std::string[quantidade];

  total_pedidos++;
}

Pedido::~Pedido() {
  if (itens == nullptr) {
    delete [] itens;
  }
  
  total_pedidos--;
}

std::string Pedido::get_nome() const {
  return nome;
}

int Pedido::get_quantidade() const {
  return quantidade;
}

int Pedido::get_id() const {
  return id;
}

int Pedido::get_total() {
  return total_pedidos;
}

void Pedido::imprimir_itens() {
  std::cout << "Itens: \n";
  for (int index{0}; index < quantidade; index++) {
    std::cout << " - " << this->itens[index] << std::endl;
  }
}

bool Pedido::get_pedido(int pos, std::string& pedido) const {
  if (pos >= 0 && pos < this->quantidade) {
    pedido = this->itens[pos];

    return true;
  } else {
    return false;
  }
}

bool Pedido::add_pedido(int pos, std::string pedido) {
  if (pos >= 0 && pos < this->quantidade) {
    this->itens[pos] = pedido;

    return true;
  } else {
    return false;
  }
}