#include <iostream>
#include "Funcionario.h"
using namespace std;

int main(void) {
    cout << Funcionario::get_total_funcionarios() << endl << endl;

    Funcionario f1("João", 5000, 2);

    f1.set_lista_empresa(0, "Amazon");
    f1.set_lista_empresa(1, "Google");

    string e1, e2;

    f1.get_lista_empresa(0, e1);
    f1.get_lista_empresa(1, e2);

    cout << f1.get_id() << endl;
    cout << f1.get_nome() << endl;
    cout << f1.get_salario() << endl;
    cout << e1 << endl;
    cout << e2 << endl;

    return 0;
}