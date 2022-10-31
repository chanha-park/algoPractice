#include <stdio.h>
#include <stdlib.h>

int info[100000][2];
int dp[100000][2];
int n;

int max(int a, int b) {
  return (a > b ? a : b);
}

void tc(void) {
  scanf("%d", &n);

  for (int i = 0; i < (2 * n); ++i) {
    scanf("%d", &info[i % n][i / n]);
  }

  if (n == 1) {
    printf("%d\n", max(info[0][0], info[0][1]));
    return;
  }

  dp[0][0] = info[0][0];
  dp[0][1] = info[0][1];
  dp[1][0] = info[1][0] + dp[0][1];
  dp[1][1] = info[1][1] + dp[0][0];
  for (int i = 2; i < n; ++i) {
    dp[i][0] = info[i][0] + max(dp[i - 1][1], dp[i - 2][1]);
    dp[i][1] = info[i][1] + max(dp[i - 1][0], dp[i - 2][0]);
  }
  printf("%d\n",
         max(max(dp[n - 1][0], dp[n - 1][1]), max(dp[n - 2][0], dp[n - 2][1])));
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--)
    tc();
  return (0);
}
