#include "Pedido.h"

int Pedido::total_pedidos = 0;

Pedido::Pedido(std::string nome, int quantidade) {
  this->nome = nome;
  this->quantidade = quantidade;
  itens = new std::string(quantidade);

  total_pedidos++;
}

Pedido::~Pedido() {
  // delete pedidosPtr;
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
  for (int index{0}; index < quantidade; index++) {
    std::cout << " ";
  }
}