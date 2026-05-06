#include <stdio.h>

struct pc {
  char name[50];
  char so[20];
  int cpu;
  double ram;
  double gdram;
  int ssd;
};


int main(void) {

  struct pc meuPC = {name: "pc da nasa", so: "linux", cpu: 4, ram: 16.5, ssd: 942, gdram: 6};

  printf("O %s usa o s.o %s, tem cpu %d, %.1lfGB ram, %dGB e %.1lfGB gdram\n", 
    meuPC.name,
    meuPC.so,
    meuPC.cpu,
    meuPC.ram,
    meuPC.ssd,
    meuPC.gdram
  );
  
  return 0;
}