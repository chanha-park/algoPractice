#include <stdio.h>

char arr[100008 >> 3];

long countDigit(long n) {
  long count = 1;
  while (n > 0) {
    count *= 10;
    n /= 10;
  }
  return (count);
}

int main(void) {
  long n, k, d, a, ans;
  scanf("%ld %ld", &n, &k);

  d = countDigit(n);
  n %= k;
  ans = 1;
  arr[n >> 3] |= 1 << (n & 7);
  a = n;
  while (n % k) {
    ++ans;
    n = (n * d + a) % k;
    if (arr[n >> 3] & (1 << (n & 7))) {
      printf("-1\n");
      return (0);
    }
    arr[n >> 3] |= 1 << (n & 7);
  }

  printf("%ld\n", ans);
  return (0);
}
