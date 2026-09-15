#include "Data.h"

Data::Data(int d, int m, int a) {
  ano = 2000;
  mes = 1;
  dia = 1;

  set_ano(a);
  set_mes(m);
  set_dia(d);
}

Data::Data() {
  ano = 2000;
  mes = 1;
  dia = 1;
}

Data::~Data() {
  std::cout << "Data apagada!\n";
}

int Data::get_dia() {
  return dia;
}

int Data::get_mes() {
  return mes;
}

int Data::get_ano() {
  return ano;
}

bool Data::set_dia(int d) {
  if (!this->valida_data(d, mes, ano)) return false;

  this->dia = d;

  return true;
}

bool Data::set_mes(int m) {
  if (!this->valida_data(dia, m, ano)) return false;
  
  mes = m;

  return true;
}

bool Data::set_ano(int a) {
  if(!this->valida_data(dia, mes, a)) return false;
  
  ano = a;

  return true;
}

bool Data::set_data(int d, int m, int a) {
  if(!this->valida_data(d, m, a)) return false;

  dia = d;
  mes = m;
  ano = a;

  return true;
}

bool Data::valida_data(int d, int m, int a) {
  if (a < 1) return false;

  if (m < 1 || m > 12) return false;

  if (d < 1 || d > 31) return false;

  // Mês até 30
  if (m = 2 || m == 4 || m == 6 || m == 9 || m == 11) {
    if (d  == 31) return false;

  }
  
  // Ano bissexto
  if (m == 2) {
    // Ano - Século
    if (a % 100 == 0) {
      if (a % 400 == 0) {
        if (d > 29) return false;
      } else {
        if (d > 28) return false;
      }
    } else {
      if (a % 4 == 0) {
        if (d > 29) return false;
      } else {
        if (d > 28) return false;
      }
    }
  }

  return true;
}

void Data::mostra_data() {
 std::cout << get_dia() << "/" << get_mes() << "/" << get_ano() << std::endl; 
}

void Data::avanca_data() {
  if (!set_dia(dia + 1)) {
    if(!set_mes(mes + 1)) {
      set_ano(ano + 1);
      set_mes(1);
    }

    set_dia(1);
  }
};

void Data::retrocede_data() {

};