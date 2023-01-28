#include <math.h>
#include <stdio.h>

int
main(void) {
  double r, h, d1, a1, d2, a2, t;
  while (scanf("%lf %lf %lf %lf %lf %lf", &r, &h, &d1, &a1, &d2, &a2) == 6) {
    a1 *= M_PI / 180.0;
    a2 *= M_PI / 180.0;
    a1 = fabs(a1 - a2);
    if (a1 > M_PI)
      a1 = 2 * M_PI - a1;
    t = cos(a1 * r / sqrt(h * h + r * r));
    printf("%.2lf\n", sqrt(d1 * d1 + d2 * d2 - 2 * d1 * d2 * t));
  }
  return (0);
}
