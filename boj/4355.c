#include <stdio.h>

int totient(int n) {
  int count, p, factor;

  count = 1;
  p = 2;
  while (p <= n / p) {
    factor = 1;
    while (n % p == 0) {
      factor *= p;
      n /= p;
    }
    if (factor > 1)
      count *= (p - 1) * (factor / p);
    ++p;
  }
  if (n > 1)
    count *= (n - 1);
  return (count);
}

int main(void) {
  int n;

  while (scanf("%d", &n) == 1 && n) {
    if (n == 1)
      printf("0\n");
    else
      printf("%d\n", totient(n));
  }
  return (0);
}
