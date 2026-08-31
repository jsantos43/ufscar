#include <iostream>
using namespace std;

typedef struct {
  int hora;
  int minuto;
  int segundo;  
} horario;

void setar_horario(horario *tempo, int h, int m, int s) {
  tempo->hora = h;
  tempo->minuto = m;
  tempo->segundo = s;
}

void imprimir_horario_12h(horario tempo) {
  if (tempo.hora > 12) {
    cout << tempo.hora - 12 << ":" << tempo.minuto << ":" << tempo.segundo << " pm\n";
  } else {
    cout << tempo.hora << ":" << tempo.minuto << ":" << tempo.segundo << " am\n";
  }

}

void imprimir_horario_24h(horario tempo) {
  cout << tempo.hora << ":" << tempo.minuto << ":" << tempo.segundo << endl;
}


int main(void) {
  horario novo_tempo;
  
  setar_horario(&novo_tempo, 17, 24, 39);

  imprimir_horario_12h(novo_tempo);
  imprimir_horario_24h(novo_tempo);
  
  return 0;
}
