#include <stdio.h>

#define MOD 1000000000

int dp[101][10];

int stairNum_k(int n, int k) {
  if (dp[n][k])
    return (dp[n][k]);

  if (n == 1) {
    dp[n][k] = 1;
  } else {
    int total = 0;

    if (k > 0)
      total += stairNum_k(n - 1, k - 1);
    if (k < 9)
      total += stairNum_k(n - 1, k + 1);
    total %= MOD;
    dp[n][k] = total;
  }
  return (dp[n][k]);
}

int stairNum(int n) {
  int total = 0;

  for (int i = 1; i < 10; i++) {
    total += stairNum_k(n, i);
    total %= MOD;
  }
  return (total);
}

int main(void) {
  int n;

  scanf("%d", &n);
  printf("%d\n", stairNum(n));
  return (0);
}
