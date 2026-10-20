#include "Fracao.h"

Fracao::Fracao()
  : num(0), den(0) 
{

}

Fracao::Fracao(int n, int d)
  : num(n), den(d) 
{

}

bool Fracao::set_num(int n) {
  num = n;

  return true;
}

bool Fracao::set_den(int d) {
  if (d == 0) return false;

  den = d;

  return true;
}

int Fracao::get_num() const {
  return num;
}

int Fracao::get_den() const {
  return den;
}

void Fracao::print() {
  std::cout << num << "/" << den << std::endl;
}

Fracao Fracao::multi(const Fracao f2) const {
  Fracao f3;
  
  f3.set_num(get_num() * f2.get_num());
  f3.set_den(get_den() * f2.get_den());
  
  return f3;
}

/*
=================
ADIÇÃO
=================
*/

Fracao Fracao::operator+(const Fracao& fd) const {
  Fracao fout;

  if (fd.den == den) {
    fout.num = fd.num + num;
    fout.den = den;
  } else {
    fout.num = (fd.den * num) + (fd.num * den);
    fout.den = den * fd.den;
  }

  return fout;
}

Fracao Fracao::operator+(int n) const {
  Fracao fout;

  fout.num = num + n * den;
  fout.den = den;

  return fout;
}

/*
=====================
SUBTRAÇÃO
=====================
*/

Fracao Fracao::operator-(const Fracao& fd) const {
  Fracao fout;

  if (fd.den == den) {
    fout.num = num - fd.num;
    fout.den = den;
  } else {
    fout.num = (fd.den * num) - (fd.num * den);
    fout.den = den * fd.den;
  }

  return fout;
}

Fracao Fracao::operator-(int n) const {
  Fracao fout;

  fout.num = num - n * den;
  fout.den = den;

  return fout;
};

/*
=======================
MULTIPLICAÇÃO
=======================
*/

Fracao Fracao::operator*(const Fracao& fd) const {
  Fracao fout;
  
  fout.num = num * fd.num;
  fout.den = den * fd.den;
  
  return fout;
}

Fracao Fracao::operator*(const int n) const {
  Fracao fout;
  
  fout.num = num * n;
  fout.den = den;
  
  return fout;
}

Fracao Fracao::multi(const Fracao f1, const Fracao f2) {
  Fracao f3;

  f3.set_num(f1.get_num() * f2.get_num());
  f3.set_den(f1.get_den() * f2.get_den());

  return f3;
}

Fracao & Fracao::operator++() {
  num = num + den;
  return * this;
}

// Fracao Fracao::operator++(int) {
//   Fracao CopiaAntes(num, den);
//   num = num + den;
//   return CopiaAntes;
// }

bool Fracao::operator==(const Fracao& f) const {
  return (f.den == den && f.num == num);
}

bool Fracao::operator<(const Fracao& f) const {
  return ((f.den / f.num) <  (den < num));
}