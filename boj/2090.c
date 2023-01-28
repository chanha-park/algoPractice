#include <stdio.h>

long
gcd(long a, long b) {
  if (a % b == 0)
    return (b);
  return (gcd(b, a % b));
}

int
main(void) {
  long n, prod, sum, g;
  int i;
  int a[9];
  scanf("%ld", &n);
  prod = 1;
  sum = 0;
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    prod *= a[i];
  }
  for (i = 0; i < n; ++i) {
    sum += prod / a[i];
  }
  g = gcd(sum, prod);
  printf("%ld/%ld\n", prod / g, sum / g);
  return (0);
}
