int printf(const char *restrict format, ...);
int scanf(const char *restrict format, ...);
double converter_horario(int, int, int);

int main() {
  int horas, minutos, segundos;

  printf("Digite um horário(hr,min,seg): ");
  scanf("%dh%dmin%ds", &horas, &minutos, &segundos);

  double horario = converter_horario(horas, minutos, segundos);
  printf("Em horas: %.4lf\n", horario);
  
  return 0;
}

double converter_horario(int horas, int minutos, int segundos) {
  return (horas + minutos / 60.0 + segundos / 3600.0);
}