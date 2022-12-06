#include <stdio.h>

int p;

int fn(long n) {
  int count1;
  int count2;

  count1 = 0;
  count2 = 0;
  while (n > 0) {
    switch (n % p) {
      case (0):
        break;
      case (1):
        count1++;
        break;
      case (2):
        count2 |= 1;
        break;
      default:
        return (0);
    }
    n /= p;
  }
  return (count1 == 2 - count2);
}

int main(void) {
  long n[4];
  int i;
  scanf("%d %ld %ld %ld %ld", &p, &n[0], &n[1], &n[2], &n[3]);
  for (i = 0; i < 4; ++i)
    printf("%d ", fn(n[i]));
  return (0);
}
