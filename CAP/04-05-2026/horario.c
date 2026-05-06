#include <stdio.h>
#include <unistd.h>

int main(void) {
  struct horario {
    int horas, minutos, segundos;
  };

  struct horario agora;
  agora.horas = 16;
  agora.minutos = 9;
  agora.segundos = 32;

  for (int index = 1; index < 10; index++) {
    printf("%02dh %02dmin %02ds\n", agora.horas, agora.minutos, agora.segundos);
    agora.segundos++;
    sleep(1);
  }

  
  
}