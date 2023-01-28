#include <stdio.h>

int gcd(int a, int b) {
  if (a < b)
    return (gcd(b, a));
  if (a % b == 0)
    return (b);
  return (gcd(b, a % b));
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  int d = gcd(n, m);
  printf("%d\n", m - d);
  return (0);
}
