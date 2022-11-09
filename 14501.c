#include <stdio.h>

int n;
int info[15][2];
int dp[15];

int max(int a, int b) {
  return (a > b ? a : b);
}

int f(int start) {
  if (start >= n)
    return (0);
  if (dp[start] == 0) {
    if (start + info[start][0] > n)
      dp[start] = f(start + 1);
    else
      dp[start] = max(info[start][1] + f(start + info[start][0]), f(start + 1));
  }
  return (dp[start]);
}

int main(void) {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d %d", &info[i][0], &info[i][1]);
  }

  printf("%d", f(0));
  return (0);
}
