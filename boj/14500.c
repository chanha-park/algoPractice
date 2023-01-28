#include <stdio.h>

int max;
int sum;
int n, m;
int map[500][500];
int visit[500][500];

void dfs(int i, int j, int depth) {
  if (i < 0 || j < 0 || i >= n || j >= m || visit[i][j])
    return;

  visit[i][j] = 1;
  sum += map[i][j];
  if (depth == 1) {
    if (sum > max)
      max = sum;
  } else {
    dfs(i + 1, j, depth - 1);
    dfs(i - 1, j, depth - 1);
    dfs(i, j + 1, depth - 1);
    dfs(i, j - 1, depth - 1);
  }
  sum -= map[i][j];
  visit[i][j] = 0;
}

void check_(int i, int j) {
  int c;

  if (i + 1 < n && j + 2 < m) {
    c = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i][j + 2];
    if (c > max)
      max = c;
    c = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
    if (c > max)
      max = c;
  }
  if (i + 2 < n && j + 1 < m) {
    c = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
    if (c > max)
      max = c;
    c = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
    if (c > max)
      max = c;
  }
}

int main(void) {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum = 0;
      dfs(i, j, 4);
      check_(i, j);
    }
  }
  printf("%d\n", max);
  return (0);
}
