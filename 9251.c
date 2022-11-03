#include <stdio.h>

// longest common sequence, lcs, LCS

char s1[1001];
char s2[1001];
int dp[1001][1001];

int max(int a, int b) {
  return (a > b ? a : b);
}

int main(void) {
  scanf("%s\n%s", s1, s2);
  int a, b;
  for (a = 1; s1[a - 1]; ++a) {
    for (b = 1; s2[b - 1]; ++b) {
      if (s1[a - 1] == s2[b - 1])
        dp[a][b] = 1 + dp[a - 1][b - 1];
      else
        dp[a][b] = max(dp[a][b - 1], dp[a - 1][b]);
    }
  }
  printf("%d\n", dp[a - 1][b - 1]);
  return (0);
}
