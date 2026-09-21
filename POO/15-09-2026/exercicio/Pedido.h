#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <string>

class Pedido {
  private:
    int id;
    std::string nome;
    int quantidade;
    std::string *itens;

    static int total_pedidos;
  public:
    Pedido(std::string, int);
    std::string get_nome() const;
    int get_quantidade() const;
    int get_id() const;
    void imprimir_itens();

    static int get_total();
};

#endif