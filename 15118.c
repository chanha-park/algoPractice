#include <math.h>
#include <stdio.h>

int
main(void) {
  long n, k;
  scanf("%ld", &n);
  k = (long)(1 + sqrt(1 + 2 * n * (n - 1))) >> 1;
  if (((k * (k - 1)) >> 1) > ((n * (n - 1)) >> 2))
    k--;
  printf("%ld\n", n - k);
  return (0);
}
