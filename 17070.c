#include <stdio.h>

enum {
  HORI,
  VERT,
  DIAG
};

int n;
int map[16][16];
int dp[16][16][3];

int f(int x, int y, int dir);

int check(int x, int y, int dir) {
  if (x >= 0 && x < n && y >= 0 && y < n && map[x][y] == 0) {
    if (dir != DIAG)
      return (f(x, y, dir));
    else if (map[x - 1][y] || map[x][y - 1])
      return (0);
    else
      return (f(x, y, dir));
  }
  return (0);
}

int f(int x, int y, int dir) {
  if (x == n - 1 && y == n - 1)
    return (1);
  if (dp[x][y][dir])
    return (dp[x][y][dir]);
  dp[x][y][dir] = check(x + 1, y + 1, DIAG);
  if (dir != HORI)
    dp[x][y][dir] += check(x + 1, y, VERT);
  if (dir != VERT)
    dp[x][y][dir] += check(x, y + 1, HORI);
  return (dp[x][y][dir]);
}

int main(void) {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      scanf("%d", &map[i][j]);
    }
  }
  printf("%d\n", f(0, 1, HORI));
  return (0);
}
