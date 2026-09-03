#include <iostream>
#include "Jogador.h"

using namespace std;

int main(void) {
  Jogador heroi {"Heroi"};
  heroi.imprimir_dados();
  heroi.aumentar_exp(500);
  heroi.imprimir_dados();
  heroi.regenerar_vida();
  heroi.regenerar_energia();
  heroi.imprimir_dados();
  
  Jogador vilao {"Vilao"};
  vilao.aumentar_exp(1000);
  vilao.perder_energia();
  vilao.perder_energia();
  vilao.perder_energia();
  vilao.imprimir_dados();
  
  
  Jogador villager;
  villager.aumentar_exp(100);
  villager.imprimir_dados();
  while (villager.get_vivo()) {
    villager.perder_vida();
  }
  villager.imprimir_dados();

  while (vilao.get_vivo()) {
    vilao.perder_vida();
    vilao.perder_energia();

    heroi.perder_energia();
  }

  vilao.imprimir_dados();
  heroi.imprimir_dados();

  return 0;
}