#include <stdio.h>

char buff[61];
int idx;

int main(void) {
  unsigned long a, b;
  int i;
  scanf("%lu %lu", &a, &b);

  if ((b & 1) == 0)
    return (printf("-1\n"), 0);

  for (i = 0; i < 60; ++i) {
    if (((1UL << (i + 1)) - 1) % b == 0) {
      unsigned long s = (((1UL << (i + 1)) - 1) / b) * a;
      unsigned long mask = 1UL << i;
      while (mask > 0) {
        buff[idx++] = (s & mask) ? '*' : '-';
        mask >>= 1;
      }
      return (printf("%s\n", buff), 0);
    }
  }
  return (printf("-1\n"), 0);
}
