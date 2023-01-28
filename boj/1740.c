#include <stdio.h>

int main(void) {
  long long n;
  long long sum = 0;
  long long tmp = 1;

  scanf("%lld", &n);
  while (n > 0) {
    if (n & 1)
      sum += tmp;
    n >>= 1;
    tmp *= 3;
  }
  printf("%lld\n", sum);
  return (0);
}
