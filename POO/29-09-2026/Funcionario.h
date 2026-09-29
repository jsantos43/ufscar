#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
    private:
        const int id;
        std::string nome;
        int salario;

        const int total_empresas_anterios;
        std::string *lista_empresas;

        static int prox_id;
        static int total_funcionarios;
    public:
        Funcionario(std::string, int, int);
        ~Funcionario();
        Funcionario(const Funcionario&);
        int get_id() const;
        std::string get_nome() const;
        int get_salario() const;
        int get_total_empresas_anteriores() const;
        bool set_nome(std::string);
        bool set_salario(int);
        bool set_lista_empresa(int, std::string);
        bool get_lista_empresa(int, std::string&);


        static int get_total_funcionarios();
};

#endif