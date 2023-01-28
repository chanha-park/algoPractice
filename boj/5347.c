#include <stdio.h>

int gcd(int a, int b) {
  if (a < b)
    return (gcd(b, a));
  if (a % b == 0)
    return (b);
  return (gcd(b, a % b));
}

long long lcm(int a, int b) {
  long long x = a / gcd(a, b);
  return (x * b);
}

int main(void) {
  int t, a, b;

  scanf("%d", &t);

  while (t--) {
    scanf("%d %d", &a, &b);
    printf("%lld\n", lcm(a, b));
  }
  return (0);
}
