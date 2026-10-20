#ifndef FRACAO_H
#define FRACAO_H

#include <iostream>

class Fracao {
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
    Fracao operator*(const Fracao) const;
    Fracao operator*(const int) const;
    Fracao & operator++();
    // Fracao operator++(int);
    bool operator==(const Fracao&) const;
    bool operator<(const Fracao&) const;
    void print();

    static Fracao multi(const Fracao, const Fracao);
};

#endif