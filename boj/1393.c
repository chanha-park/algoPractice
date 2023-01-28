#include <stdio.h>

int gcd(int a, int b) {
  if (a == 0 || b == 0)
    return (1);
  if (a % b == 0)
    return (b);
  return (gcd(b, a % b));
}

int main(void) {
  int xs, ys, xe, ye, dx, dy, g, k;
  scanf("%d %d", &xs, &ys);
  scanf("%d %d %d %d", &xe, &ye, &dx, &dy);
  g = gcd(dx >= 0 ? dx : -dx, dy >= 0 ? dy : -dy);
  dx /= g;
  dy /= g;

  if (dx != 0 || dy != 0) {
    if (dx == 0)
      dy = dy > 0 ? 1 : -1;
    else if (dy == 0)
      dx = dx > 0 ? 1 : -1;
    k = (dx * (xs - xe) + dy * (ys - ye)) / (dx * dx + dy * dy);
    if (k < 0)
      k = 0;
    printf("%d %d\n", xe + k * dx, ye + k * dy);
  } else
    printf("%d %d\n", xe, ye);

  return (0);
}

/* (xe + kdx - xs, ye + kdy - ys) * (dx, dy) = 0         */

/* dx (xe + kdx - xs) + dy (ye + kdy - ys)               */

/* k = dx (xs - xe) + dy (ys - ye) / (dx * dx + dy * dy) */
