#include <stdio.h>

// utils - factorize, Factorize, find divisor

typedef struct {
  unsigned long long prime;
  int order;
} pair;

pair buff[25];
int idx;

int main(void) {
  unsigned long long n;
  scanf("%llu", &n);
  printf("Factorization of %llu:\n", n);

  int count = 0;
  while (n % 2 == 0) {
    n >>= 1;
    count++;
  }
  if (count)
    buff[idx++] = (pair){2, count};

  for (unsigned long long i = 3; i <= n / i; i += 2) {
    int count = 0;
    while (n % i == 0) {
      n /= i;
      count++;
    }
    if (count > 0)
      buff[idx++] = (pair){i, count};
  }
  if (n > 1)
    buff[idx++] = (pair){n, 1};

  for (int i = 0; i < idx; ++i) {
    printf("%llu ^ %d\n", buff[i].prime, buff[i].order);
  }
  return (0);
}
