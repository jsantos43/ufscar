#include "Data.h"
#include <iostream>
using namespace std;

int main(void) {
  Data meu_niver(3, 5, 2007);

  meu_niver.mostra_data();

  Data data1;

  
  cout << "O ano é: " << data1.get_ano() << endl;
  cout << "O ano é: " << data1.get_mes() << endl;
  cout << "O ano é: " << data1.get_dia() << endl;
  
  

  data1.avanca_data();

  return 0;
}