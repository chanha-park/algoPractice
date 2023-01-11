#include <stdio.h>

#define MOD 1000000007

long
calc(int x, int k) {
  long ret;
  long bit;

  ret = 0;
  bit = 1;
  while (k > 0) {
    if (k & 1)
      ret = (ret + bit) % MOD;
    k >>= 1;
    bit = (bit * x) % MOD;
  }
  return (ret);
}

int
main(void) {
  int n, x, k;
  long sum;
  scanf("%d", &n);
  sum = 0;
  while (n--) {
    scanf("%d %d", &x, &k);
    sum = (sum + calc(x, k)) % MOD;
  }
  printf("%ld\n", sum);
  return (0);
}
