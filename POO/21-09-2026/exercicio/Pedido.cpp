#include "Pedido.h"

int Pedido::total_pedidos = 0;
int Pedido::total_itens = 0;
int Pedido::prox_id = 1;

Pedido::Pedido(std::string nome, int quantidade) 
  : id(prox_id++), nome(nome), quantidade(quantidade),
    itens(nullptr) {

  itens = new std::string[quantidade];
  total_pedidos++;
  total_itens += quantidade;
}

Pedido::Pedido(const Pedido& pedido)
  : id(prox_id++), nome(pedido.nome), quantidade(pedido.quantidade),
    itens(nullptr) {
  
  itens = new std::string[quantidade];
  total_pedidos++;
  total_itens += quantidade;

  for (int index{0}; index < pedido.quantidade; index++) {
    itens[index] = pedido.itens[index];
  }
}

Pedido::~Pedido() {
  delete [] itens;
  
  total_pedidos--;
  total_itens -= quantidade;
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

int Pedido::get_total_pedidos() {
  return total_pedidos;
}

int Pedido::get_total_itens() {
  return total_itens;
}

void Pedido::imprimir() const {
  std::cout << "\n\n";
  std::cout << "==========================" << std::endl;
  std::cout << "Pedido #" << get_id() << std::endl;
  std::cout << "Nome: " << get_nome() << std::endl;
  std::cout << "Quantidade: " << get_quantidade() << std::endl; 
  std::cout << "Itens: \n";
  for (int index{0}; index < quantidade; index++) {
    std::cout << " - " << this->itens[index] << std::endl;
  }
  std::cout << "Total Pedidos: " << get_total_pedidos() << std::endl;
  std::cout << "Total Itens: " << get_total_itens() << std::endl;
  std::cout << "==========================" << std::endl;
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
