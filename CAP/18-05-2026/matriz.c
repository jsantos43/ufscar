#include <stdio.h>

int main(void) {
  double m1[3][2];

  m1[0][0] = 7.56;
  m1[2][1] = 0.5;

  printf("m0,0 = %g\n", m1[0][0]);
  printf("m0,1 = %g\n", m1[0][1]);
  printf("m1,0 = %g\n", m1[1][0]);
  printf("m1,1 = %g\n", m1[1][1]);
  printf("m2,0 = %g\n", m1[2][0]);
  printf("m2,1 = %g\n", m1[2][1]);

  printf("\n");

  double m2[2][3] = { 
    {1, 2, 3}, 
    {4, 5, 6}
  };

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("m[%d][%d] = %g\n", i, j, m2[i][j]);
    }
  }

  printf("\n");

  int m3[5][4] = {
    {1, 2, 3, 4},
    {10},
    {11, 12, 13},
    {0}
  };


  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      printf("m[%d][%d] = %d\n", i, j, m3[i][j]);
    }
  }

  printf("\n");

  int zeros[10][7] = { {0} };

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 7; j++) {
      printf("%2d ", zeros[i][j]);
    }

    printf("\n");
  }

  return 0;
}