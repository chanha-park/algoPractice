#include <stdio.h>

int
f(int n, int mask, int k) {
  if (n == 0)
    return (0);
  if (n >= mask)
    return (k * (n - mask + 1) + f(mask - 1, mask / 10, k - 1));
  return (f(n, mask / 10, k - 1));
}

int
main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n", f(n, 100000000, 9));
  return (0);
}
