#include "Fila.h"

Fila::Fila() {
  total_elementos = 0;
  primeiro = nullptr;
  ultimo = nullptr;
}

bool Fila::vazia() {
  return (this->ultimo == nullptr && this->primeiro == nullptr);
}

void Fila::inserir(char elemento) {
  if (this->vazia() == false) {
    Node* pNovo = new Node{ elemento, nullptr };

    this->ultimo->next=pNovo;
    this->ultimo = pNovo;
    this->ultimo->next = this->primeiro;
  } else {
    Node* pNovo = new Node{ elemento, nullptr };

    pNovo->next = pNovo;

    this->ultimo = pNovo;
    this->primeiro = pNovo;
  }

  this->total_elementos++;
}

char Fila::retirar() {
  if (this->vazia() == true) return ' ';

  Node* pAux = this->primeiro;

  char elemento = this->primeiro->elemento;
  this->primeiro = pAux->next;

  delete pAux;

  this->ultimo->next = this->primeiro;

  this->total_elementos--;

  if (total_elementos <= 0) {
    this->primeiro = nullptr;
    this->ultimo = nullptr;
  }

  return elemento;
}

void Fila::imprimir() {
  Node* pAtual = this->primeiro;

  std::cout << std::endl << "["; 

  for (int counter {0}; counter < this->total_elementos; counter++) {
    std::cout << " " << pAtual->elemento << " ";
    
    pAtual = pAtual -> next;
  }

  std::cout << "]" << std::endl;
}

bool Fila::iguais(Fila *F1, Fila *F2) {
  if (F1->total_elementos == F2->total_elementos) {
    const int quantidade {F1->total_elementos};

    Fila F1_Aux;
    Fila F2_Aux;

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