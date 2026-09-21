#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <string>

class Pedido {
  private:
    const int id;
    const std::string nome;
    const int quantidade;
    std::string *itens;

    static int total_pedidos;
  public:
    Pedido(std::string, int);
    ~Pedido();
    std::string get_nome() const;
    int get_quantidade() const;
    int get_id() const;
    bool get_pedido(int, std::string&) const;
    bool add_pedido(int, std::string);
    void imprimir_itens();

    static int get_total();
};

#endif