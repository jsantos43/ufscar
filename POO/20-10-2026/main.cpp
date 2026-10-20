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

ostream &operator<<(ostream& output, const Fracao& f) {
  output << f.get_num() << "/" << f.get_den();
  return output;
}

int main(void) {
  Fracao f1(-5, 2);
  Fracao f2;
  Fracao f3;
  Fracao f4;
  Fracao f5;
  Fracao f6;
  Fracao f7;
  Fracao f8;
  Fracao f9;
  Fracao f10;
  Fracao f11;

  f2.set_den(10);
  f2.set_num(3);

  f3.set_num(7);
  f3.set_den(1);
  f3.set_den(0);

  f5 = Fracao::multi(f1, f3);
  f6 = f2.multi(f5);
  f7 = f1 * f6;
  f8 = f7 * 2;
  f9 = 5 * f8;
  
  cout << f1 << endl;
  cout << f2 << endl;
  cout << f3 << endl;
  cout << f4 << endl;
  cout << f5 << endl;
  cout << f6 << endl;
  cout << f7 << endl;
  cout << f8 << endl;
  cout << f9 << endl;

  // f10 = ++f1;
  f11 = f10++;
  
  f10.print();
  f11.print();
  f10.print();
  cout << boolalpha;
  cout << (f10 == f10) << endl;
  cout << (f3 < f1) << endl;
  cout << (f2 < f1) << endl;

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


  return 0;
}