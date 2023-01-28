#include <stdio.h>

typedef struct {
  int x;
  int y;
} point;

point f(int n, int m) {
  point p;
  const int q = ((n * n) >> 2);

  if (n == 2) {
    p.x = 1 + (m > 2);
    p.y = 1 + ((m - 1) % 3 != 0);
    return (p);
  }
  if (m <= q) {
    point r = f(n >> 1, m);
    p.x = r.y;
    p.y = r.x;
    return (p);
  }
  if (m <= 2 * q) {
    point r = f(n >> 1, m - q);
    p.x = r.x;
    p.y = r.y + (n >> 1);
    return (p);
  }
  if (m <= 3 * q) {
    point r = f(n >> 1, m - 2 * q);
    p.x = r.x + (n >> 1);
    p.y = r.y + (n >> 1);
    return (p);
  }
  point r = f(n >> 1, m - 3 * q);
  p.x = n + 1 - r.y;
  p.y = (n >> 1) + 1 - r.x;
  return (p);
}

int main(void) {
  int n, m;
  point p;

  scanf("%d %d", &n, &m);

  p = f(n, m);
  printf("%d %d\n", p.x, p.y);

  return (0);
}

/*
   1. m <= (n * n) / 4;

   f(n, m) = g(n / 2, m);
   g(n, m) = f(n / 2, m);

   2. m <= (n * n) / 2;

   f(n, m) = f(n / 2, m - (n * n) / 4);
   g(n, m) = g(n / 2, m - (n * n) / 4) + n / 2;

   3. m <= (3 * n * n) / 4;

   f(n, m) = f(n / 2, m - (2 * n * n) / 4) + n / 2;
   g(n, m) = g(n / 2, m - (2 * n * n) / 4) + n / 2;

   4. else;

   f(n, m) = n - g(n / 2, m - (3 * n * n) / 4);
   g(n, m) = n / 2 - f(n / 2, m - (3 * n * n) / 4):


   */

