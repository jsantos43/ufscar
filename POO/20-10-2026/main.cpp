#include <iostream>
#include "Fracao.h"
using namespace std;

Fracao operator+(int n, Fracao& fd) {
  return fd + n;
}

Fracao operator-(int n, Fracao& fd) {
  Fracao fout;

  fout.num = fd.num - n * fd.den;
  fout.den = fd.den;

  return fout;
}

Fracao operator*(int n, Fracao& fd) {
  return fd * n;
}

Fracao operator++(Fracao& f, int) {
  Fracao CopiaAntes(f);
  f.num = f.num + f.den;
  return CopiaAntes;
}

Fracao operator--(Fracao& f, int) {
  Fracao CopiaAntes(f);
  f.num = f.num - f.den;
  return CopiaAntes;
}

ostream &operator<<(ostream& output, const Fracao& f) {
  output << f.get_num() << "/" << f.get_den();
  return output;
}

istream &operator>>(istream& input, Fracao& f) { 
  int num, den;

  input >> num; 
  input.ignore();
  input >> den;

  f.set_num(num);
  f.set_den(den);

  return input;            
}

int main(void) {
  Fracao f1(-5, 2);
  Fracao f2;

  f2.set_den(10);
  f2.set_num(3);

  cout << boolalpha;

  cout << endl;
  cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
  cout << f1 << " + " << 2 << " = " << (f1 + 2) << endl;
  cout << 2 << " + " << f1 << " = " << (2 + f1) << endl;
  cout << -2 << " + " << f1 << " = " << (-2 + f1) << endl;

  cout << endl;
  cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
  cout << f1 << " - " << 2 << " = " << (f1 - 2) << endl;
  cout << 2 << " - " << f1 << " = " << (2 - f1) << endl;

  cout << endl;
  cout << f1 << " * " <<  f2 << " = " << (f1 * f2) << endl;
  cout << f1 << " * " <<  2 << " = " << (f1 * 2) << endl;
  cout << 2 << " * " <<  f1 << " = " << (2 * f1) << endl;

  cout << endl;
  cout << "(" << f1 << ")++ = " << f1++ << endl;
  cout << "f = " << f1 << endl;
  cout << "++(" << f1 << ") = " << ++f1 << endl;

  cout << endl;
  cout << "(" << f1 << ")-- = " << f1-- << endl;
  cout << "f = " << f1 << endl;
  cout << "--(" << f1 << ") = " << --f1 << endl;

  cout << endl;
  cout << f1 << " == " << f2 << "? " << (f1 == f2 ? "Sim" : "Não") << endl;
  cout << f1 << " == " << f1 << "? " << (f1 == f1 ? "Sim" : "Não") << endl;
  cout << f1 << " != " << f1 << "? " << (f1 != f1 ? "Sim" : "Não") << endl;
  cout << f1 << " != " << f2 << "? " << (f1 != f2 ? "Sim" : "Não") << endl;
  cout << f1 << " < " << f2 << "? " << (f1 < f2 ? "Sim" : "Não") << endl;
  cout << f1 << " > " << f2 << "? " << (f1 > f2 ? "Sim" : "Não") << endl;
  cout << f1 << " <= " << f1 << "? " << (f1 <= f1 ? "Sim" : "Não") << endl;
  cout << f1 << " >= " << f2 << "? " << (f1 >= f2 ? "Sim" : "Não") << endl;

  Fracao f3;

  cout << endl;
  cout << "f3 << ";
  cin >> f3;
  cout << "f3 = " << f3 << endl;

  return 0;
}