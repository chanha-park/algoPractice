#include <stdio.h>

typedef unsigned long ul;

int binDigit(ul n) {
  int count;

  if (n == 0)
    return (1);

  count = 0;
  while (n > 0) {
    count++;
    n >>= 1;
  }
  return (count);
}

ul f(ul n) {
  ul count;
  ul max;

  if (n <= 2)
    return (n);

  count = binDigit(n) - 1;
  max = 1UL << count;
  return ((count << (count - 1)) + f(n - max) + n - max + 1);
}

int main(void) {
  ul a, b;

  scanf("%lu %lu", &a, &b);
  printf("%lu\n", f(b) - f(a - 1));
  return (0);
}
