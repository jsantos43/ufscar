#include "Funcionario.h"

int Funcionario::prox_id = 1;
int Funcionario::total_funcionarios = 0;

Funcionario::Funcionario(std::string n, int s, int q)
    : id(prox_id), total_empresas_anterios(q) {
        set_nome(n);
        set_salario(s);
        
        lista_empresas = new std::string[total_empresas_anterios];

        prox_id++;
        total_funcionarios++;
}

Funcionario::Funcionario(const Funcionario& f)
    : id(f.id), total_empresas_anterios(f.total_empresas_anterios) {
        set_nome(f.nome);
        set_salario(f.salario);
        
        lista_empresas = new std::string[total_empresas_anterios];

        for (int index {0}; index < total_empresas_anterios; index++) {
            lista_empresas[index] = f.lista_empresas[index];
        }

        total_funcionarios++;
}

Funcionario::~Funcionario() {
    total_funcionarios--;

    delete [] lista_empresas;
}

int Funcionario::get_id() const {
    return id;
}

std::string Funcionario::get_nome() const {
    return nome;
};


int Funcionario::get_salario() const {
    return salario;
};

int Funcionario::get_total_empresas_anteriores() const {
    return total_empresas_anterios;
};

bool Funcionario::set_nome(std::string n) {
    nome = n;
    return true;
};

bool Funcionario::set_salario(int sal) {
    if (sal > 0) {
        salario = sal;

        return true;
    } else {
        return false;
    }
};

bool Funcionario::set_lista_empresa(int pos, std::string e) {
    if (pos >= 0 && pos < total_empresas_anterios) {
        lista_empresas[pos] = e;
        return true;
    } else {
        return false;
    }
}

bool Funcionario::get_lista_empresa(int pos, std::string& e) {
    if (pos >= 0 && pos < total_empresas_anterios) {
        e = lista_empresas[pos];
        return true;
    } else {
        return false;
    }
};

int Funcionario::get_total_funcionarios() {
    return total_funcionarios;
}