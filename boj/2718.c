#include <stdio.h>

int dp[30];

int g(int n) {
  if (n == 1)
    return (1);
  if (n == 2)
    return (4);
  return (3 - (n & 1));
}

int f(int n) {
  if (n == 1)
    return (1);

  if (dp[n] == 0) {
    int sum = 0;
    for (int i = 1; i < n; i++)
      sum += g(i) * f(n - i);
    dp[n] = sum + g(n);
  }
  return (dp[n]);
}

int main(void) {
  int t, n;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    printf("%d\n", f(n));
  }
  return (0);
}
