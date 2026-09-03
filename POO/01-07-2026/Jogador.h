#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>

class Jogador {
  private:
    // Atributos
    std::string nome;

    int vida;
    int exp;
    int energia;
    bool vivo;

    int max_vida;
    int max_energia;

    // Métodos
    void expandir_energia();
    void expandir_vida();
    void morrer();
  public:

    // Construtores
    Jogador();
    Jogador(std::string); 

    // Métodos
    int get_vida();
    int get_exp();
    int get_energia();
    bool get_vivo();
    int get_max_vida();
    int get_max_energia();
    std::string get_nome();

    void regenerar_vida();
    void regenerar_energia();
    
    void aumentar_exp(int);
    void perder_vida();
    void perder_energia();

    void imprimir_dados();
};

#endif