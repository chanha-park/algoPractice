#include <stdio.h>

// k % 2 == 1
long countDivisor(int k) {
  int totalCount = 1;

  for (int i = 3; i <= k / i; i += 2) {
    int count = 0;
    while (k % i == 0) {
      k /= i;
      count++;
    }
    if (count > 0)
      totalCount *= (count + 1);
  }
  if (k > 1)
    totalCount <<= 1;
  return (totalCount);
}

// a(2^n * k) = (n - 1) * countDivisor(k)

int main(void) {
  long s, t, d, sum, start, end;
  scanf("%ld %ld", &s, &t);

  sum = 0;
  start = 0;
  end = 0;
  for (int i = (t - 1 + t % 2); i >= 1; i -= 2) {
    while ((i << start) < s)
      start++;
    while ((i << end) <= t)
      end++;
    if (start < end) {
      d = countDivisor(i);
      sum += (((end - start) * (start + end - 3)) >> 1) * d;
    }
  }
  printf("%ld\n", sum);
  return (0);
}
