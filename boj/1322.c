#include <stdio.h>

int main(void) {
  long x, y, k, mask, order;

  scanf("%ld %ld", &x, &k);
  y = 0;
  mask = 1;
  order = 0;

  while (k > 0 || x > 0) {
    if (!(x & 1)) {
      if (k & 1)
        y |= mask;
      k >>= 1;
    }
    mask <<= 1;
    x >>= 1;
  }
  printf("%ld\n", y);
  return (0);
}
