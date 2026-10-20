#ifndef FRACAO_H
#define FRACAO_H

#include <iostream>

class Fracao {
  friend Fracao operator+(int, Fracao&);
  friend Fracao operator-(int, Fracao&);
  friend Fracao operator*(int, Fracao&);
  friend Fracao operator++(Fracao& f, int);
  private:
    int num;
    int den;
  public:
    Fracao();
    Fracao(int, int);
    bool set_num(int);
    bool set_den(int);
    int get_num() const;
    int get_den() const;
    Fracao multi(const Fracao) const;

    // Adição
    Fracao operator+(const Fracao&) const;
    Fracao operator+(int) const;

    // Subtração
    Fracao operator-(const Fracao&) const;
    Fracao operator-(int) const;

    // Multiplicação
    Fracao operator*(const Fracao&) const;
    Fracao operator*(const int) const;

    // Add ++ (pré e pós fixados)
    Fracao & operator++();
    // Fracao operator++(int);
    bool operator==(const Fracao&) const;
    bool operator<(const Fracao&) const;
    void print();

    static Fracao multi(const Fracao, const Fracao);
};

#endif