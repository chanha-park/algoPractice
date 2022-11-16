#include <stdio.h>
#include <string.h>

char s[10000001];

int gcd(long a, long b) {
  if (a < b)
    return (gcd(b, a));
  if (a % b == 0)
    return (b);
  return (gcd(b, a % b));
}

int main(void) {
  long a, b;
  scanf("%ld %ld", &a, &b);
  memset(s, '1', gcd(a, b));
  printf("%s\n", s);
  return (0);
}
