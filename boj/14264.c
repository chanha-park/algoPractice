#include <math.h>
#include <stdio.h>

int
main(void) {
  double l;
  scanf("%lf", &l);
  printf("%.9f", (l * l * sqrt(3)) / 4);
  return 0;
}
