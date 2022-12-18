#include <stdio.h>

int
gcd(int a, int b) {
  return (a % b ? gcd(b, a % b) : b);
}

int
getAbs(int n) {
  return (n >= 0 ? n : -n);
}

void
putFactor(int n, int p) {
  if (p > n / p)
    return;
  if (n % p == 0) {
    printf("%d ", p);
    putFactor(n, p + 1);
    if (p != n / p)
      printf("%d ", n / p);
  } else
    putFactor(n, p + 1);
}

int
main(void) {
  int n, i, g;
  int a[100];
  scanf("%d", &n);
  scanf("%d", &a[0]);
  scanf("%d", &a[1]);
  a[0] = getAbs(a[0] - a[1]);
  g = a[0];
  for (i = 2; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i - 1] = getAbs(a[i - 1] - a[i]);
    g = gcd(g, a[i - 1]);
  }
  putFactor(g, 2);
  printf("%d\n", g);
  return (0);
}
