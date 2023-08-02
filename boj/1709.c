#include <math.h>
#include <stdio.h>

int a(long k) { const long q = (long)sqrt(k); return q * q == k; }

int s(long k) {
  int c; long x;
  c = 0; k *= k;
  for (x = 1; (x << 1) < k / x; ++x) { c += a(k - x * x); }
  return c;
}

int main(void) {
  int n; scanf("%d", &n); printf("%d", (n - 1 - 2 * s(n >> 1)) << 2);
  return 0;
}
