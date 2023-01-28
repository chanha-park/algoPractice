#include <stdio.h>

int n;
int forest[500][500];
int dp[500][500];

int
max(int a, int b) {
  return (a > b ? a : b);
}

int
check(int row, int col) {
  int ret, i, nx, ny;
  static const int dx[4] = {1, 0, -1, 0};
  static const int dy[4] = {0, 1, 0, -1};

  if (dp[row][col] == 0) {
    ret = 1;
    for (i = 0; i < 4; ++i) {
      nx = row + dx[i];
      ny = col + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n
          || forest[nx][ny] <= forest[row][col])
        continue;
      ret = max(ret, 1 + check(nx, ny));
    }
    dp[row][col] = ret;
  }
  return (dp[row][col]);
}

int
main(void) {
  int ans, i, j;
  ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      scanf("%d", &forest[i][j]);
    }
  }

  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      ans = max(ans, check(i, j));
    }
  }

  printf("%d", ans);

  return (0);
}
