#include <iostream>
#include "Fracao.h"
using namespace std;

Fracao operator*(int num, Fracao fra) {
  return fra * num;
}

Fracao operator++(Fracao& f, int) {
  Fracao CopiaAntes(f);
  f.num = f.num + f.den;
  return CopiaAntes;
}

int main(void) {
  Fracao f1(5, 2);
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
  
  f1.print();
  f2.print();
  f3.print();
  f4.print();
  f5.print();
  f6.print();
  f7.print();
  f8.print();
  f9.print();

  f10 = ++f1;
  f11 = f10++;
  
  f10.print();
  f11.print();
  f10.print();
  cout << boolalpha;
  cout << (f10 == f10) << endl;
  cout << (f3 < f1) << endl;
  cout << (f2 < f1) << endl;

  return 0;
}