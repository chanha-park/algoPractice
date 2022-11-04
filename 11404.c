#include <stdio.h>

int map[100][100];

void update(int start, int end, int mid) {
  int sum;

  if (map[start][mid] && map[mid][end]) {
    sum = map[start][mid] + map[mid][end];
    if (map[start][end] && map[start][end] < sum)
      return;
    map[start][end] = sum;
  }
}

int main(void) {
  int n, m, a, b, c, i, j, k;
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; ++i) {
    scanf("%d %d %d", &a, &b, &c);
    if (map[a - 1][b - 1] && map[a - 1][b - 1] < c)
      continue;
    map[a - 1][b - 1] = c;
  }

  for (k = 0; k < n; ++k) {
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (i != j)
          update(i, j, k);
      }
    }
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
  return (0);
}
