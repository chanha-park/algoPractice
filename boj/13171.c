#include <stdio.h>

#define MOD 1000000007

int
main(void) {
  long a, x, tmp;
  scanf("%ld %ld", &a, &x);
  a %= MOD;
  tmp = 1;
  while (x > 1) {
    if (x & 1) {
      tmp *= a;
      tmp %= MOD;
    }
    a *= a;
    a %= MOD;
    x >>= 1;
  }
  printf("%ld\n", (a * tmp) % MOD);
  return (0);
}
