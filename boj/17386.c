#include <stdio.h>

double det(long long a, long long b, long long c, long long d) {
  return (a * d - b * c);
}

int main(void) {
  long long x1, y1, x2, y2, x3, y3, x4, y4;

  scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
  scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

  long long ux = x3 - x1;
  long long uy = y3 - y1;

  long long vx = x4 - x1;
  long long vy = y4 - y1;

  long long wx = x2 - x1;
  long long wy = y2 - y1;

  double a = det(wx, vx, wy, vy) / det(ux, vx, uy, vy);
  double b = det(ux, wx, uy, wy) / det(ux, vx, uy, vy);

  if (a > 0 && b > 0 && (a + b > 1))
    printf("1\n");
  else
    printf("0\n");

  return (0);
}
