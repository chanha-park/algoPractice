#include <math.h>
#include <stdio.h>

double
min3(double a, double b, double c) {
  a = a < b ? a : b;
  return a < c ? a : c;
}

int
main(void) {
  int x, y, d, t;
  double l, total;
  scanf("%d %d %d %d", &x, &y, &d, &t);
  l = sqrt((double)(x * x + y * y));
  total = 0;
  if (d < t)
    total = l;
  else {
    while (l > 2 * d) {
      total += t;
      l -= d;
    }
    total += l > t + d ? 2 * t : l > d ? t + l - d : min3(2 * t, l, t + d - l);
  }
  printf("%.9f\n", total);
  return 0;
}
