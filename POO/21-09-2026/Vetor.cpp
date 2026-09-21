#include "Vetor.h"

Vetor::Vetor(int t) {
  tamanho = t;
  vetorPtr = new int(t);
}

// Construtor de cópia
Vetor::Vetor(const Vetor& v) : tamanho(v.tamanho) {
  vetorPtr = new int[tamanho];

  for (int index {0}; index < tamanho; index++) {
    vetorPtr[index] = v.vetorPtr[index];
  }
}

Vetor::~Vetor() {
  delete [] vetorPtr;
}

bool Vetor::add(int index, int value) {
  if (index >= tamanho || index < 0) return false;

  vetorPtr[index] = value;

  return true;
}

bool Vetor::get(int index, int &value) const {
  if (index >= tamanho || index < 0) return false;

  value = vetorPtr[index];

  return true;
}

int Vetor::get_tamanho() const {
  return tamanho;
}

void Vetor::imprimir() const {
  std::cout << "[ ";

  for (int index{0}; index < tamanho; index++) {
    std::cout << vetorPtr[index] << " ";
  }

  std::cout << "] " << std::endl;
}