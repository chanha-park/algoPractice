#include <stdio.h>

int gcd(int n, int m) {
  int c;
  c = n % m;
  while (c) {
    n = m;
    m = c;
    c = n % m;
  }
  return (m);
}

int main(void) {
  int n, m, g;
  scanf("%d:%d", &n, &m);
  g = gcd(n, m);
  printf("%d:%d\n", n / g, m / g);
  return (0);
}
