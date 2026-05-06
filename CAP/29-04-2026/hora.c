#include <stdio.h>

struct horario {
  double horas, minutos, segundos;
};


struct horario converta_hora_hms(double horas) {
  struct horario horario_convertido;

  horario_convertido.horas = horas;
  horario_convertido.minutos = horas * 60;
  horario_convertido.segundos = horas * 3600;

  return horario_convertido;
}

int main() {
  double horas;

  printf("Digite uma hora(h): ");
  scanf("%lf", &horas);

  struct horario horario_convertido = converta_hora_hms(horas);

  printf("Temos %ghoras %gminutos %gsegundos\n", 
    horario_convertido.horas, 
    horario_convertido.minutos, 
    horario_convertido.segundos
  );

  return 0;
}