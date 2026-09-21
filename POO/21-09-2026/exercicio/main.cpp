#include <iostream>
#include "Pedido.h"
using namespace std;

int main(void) {
  Pedido p1("Francisco", 3);

  p1.add_pedido(0, "Bicicleta");
  p1.add_pedido(1, "Carrinho");
  p1.add_pedido(2, "Cachorro");

  Pedido p2("Maria", 2);
  p2.add_pedido(0, "Notebook");
  p2.add_pedido(1, "Escorregador");

  Pedido p3("Carlos", 1);
  p3.add_pedido(0, "Video-Game");

  p1.imprimir_itens();
  p2.imprimir_itens();
  p3.imprimir_itens();
  return 0;
}