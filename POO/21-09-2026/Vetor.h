#ifndef VETOR_H
#define VETOR

#include <iostream>

class Vetor{
  private:
    int tamanho;
    int *vetorPtr;
  public:
    Vetor(int);
    Vetor(const Vetor&);
    ~Vetor();
    bool add(int, int);
    bool get(int, int&) const;
    int get_tamanho() const;
    void imprimir() const;
};

#endif