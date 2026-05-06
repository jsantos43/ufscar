#include <stdio.h>
#include <math.h>

double obter_distancia(double x, double y, double z) {
  return sqrt((x * x) + (y * y) + (z * z));
}

int main() {
  double x, y, z;

  printf("Digite as coordenadas(x,y,z): ");
  scanf("%lf%lf%lf", &x, &y, &z);

  double distancia = obter_distancia(x, y, z);
  printf("A distancia é: %.2lf\n", distancia);

  return 0;
}