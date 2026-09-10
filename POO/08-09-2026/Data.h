#ifndef DATA_H
#define DATA_H

#include <iostream>

class Data {
  private:
    int dia;
    int mes;
    int ano;
    bool valida_data(int, int, int);
  public:
    Data(int, int, int);
    Data();
    ~Data();
    int get_dia();
    int get_mes();
    int get_ano();
    bool set_data(int, int, int);
    bool set_dia(int);
    bool set_mes(int);
    bool set_ano(int);
    void avanca_data();
    void retrocede_data();
    void mostra_data();
};

#endif