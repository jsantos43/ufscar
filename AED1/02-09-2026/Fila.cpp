#include "Fila.h"

Fila::Fila(int t) {
  ptr = new char(t);
  tamanho = t;
  total_elementos = 0;
  inicio = 0;
  fim = 0;
}

bool Fila::vazia() {
  return (this->total_elementos == 0);
}

bool Fila::cheia() {
  return (this->total_elementos >= this->tamanho);
}

bool Fila::inserir(char elemento) {
  if (this->cheia() == false) {
    this->ptr[fim] = elemento;

    if (this->fim + 1 >= this->tamanho) {
      this->fim = 0;
    } else {
      this->fim += 1;
    }

    this->total_elementos += 1;

    return true;
  } else {
    return false;
  }
}

char Fila::retirar() {
  if (this->vazia() == true) return ' ';

  char elemento = this->ptr[this->inicio];
  this->ptr[this->inicio] = ' ';

  if (this->inicio + 1 >= this->tamanho) {
    this->inicio = 0;
  } else {
    this->inicio += 1;
  }

  this->total_elementos -= 1;

  return elemento;
}

void Fila::imprimir() {
  int index {this->inicio};

  std::cout << std::endl << "["; 

  for (int counter {0}; counter < this->total_elementos; counter++) {
    std::cout << " " << this->ptr[index] << " ";
    
    if (index + 1 >= tamanho) {
      index = 0;
    } else {
      index++;
    }
  }

  std::cout << "]" << std::endl;
}

bool Fila::iguais(Fila *F1, Fila *F2) {
  if (F1->total_elementos == F2->total_elementos) {
    const int quantidade {F1->total_elementos};

    Fila F1_Aux(quantidade);
    Fila F2_Aux(quantidade);

    char elemento1;
    char elemento2;

    bool iguais {true};

    for (int index{0}; index < quantidade; index++) {
      elemento1 = F1->retirar();
      elemento2 = F2->retirar();

      F1_Aux.inserir(elemento1);
      F2_Aux.inserir(elemento2);

      if(elemento1 != elemento2) {
        iguais = false;
      }
    }

    for (int index{0}; index < quantidade; index++) {
      elemento1 = F1_Aux.retirar();
      elemento2 = F2_Aux.retirar();

      F1->inserir(elemento1);
      F2->inserir(elemento2);
    }

    return iguais;
  } else {
    return false;
  }
}