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

Fracao Fracao::operator*(const Fracao f2) const {
  Fracao f3;

  f3.set_num(get_num() * f2.get_num());
  f3.set_den(get_den() * f2.get_den());

  return f3;
}

Fracao Fracao::operator*(const int n) const {
  Fracao f3;

  f3.set_num(get_num() * n);
  f3.set_den(get_den());

  return f3;
}

Fracao Fracao::multi(const Fracao f1, const Fracao f2) {
  Fracao f3;

  f3.set_num(f1.get_num() * f2.get_num());
  f3.set_den(f1.get_den() * f2.get_den());

  return f3;
}
