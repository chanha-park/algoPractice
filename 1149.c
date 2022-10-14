#include <stdio.h>
#include <stdlib.h>

int house[1000][3];
int n;

int dp[1000][3];

int min2(int a, int b) {
  if (a > b)
    return (b);
  return (a);
}

int min3(int a, int b, int c) {
  if (a > b)
    a = b;
  if (a > c)
    return (c);
  return (a);
}

int g(int idx, int color) {
  if (dp[idx - 1][color])
    return (dp[idx - 1][color]);
  if (idx == 1)
    dp[idx - 1][color] = house[idx - 1][color];
  else
    dp[idx - 1][color]
        = house[idx - 1][color]
          + min2(g(idx - 1, (color + 1) % 3), g(idx - 1, (color + 2) % 3));
  return (dp[idx - 1][color]);
}

int f(int idx) {
  return (min3(g(idx, 0), g(idx, 1), g(idx, 2)));
}

int main(void) {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
  }

  printf("%d\n", f(n));

  return (0);
}
