#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
  private:
    int ra;
    std::string nome;

    static int contador;
    static int proxRA;
  public:
    Aluno( std::string);
    ~Aluno();
    void set_nome(std::string);
    std::string get_nome() const;
    int get_ra() const;

    static int get_contador();
};

#endif