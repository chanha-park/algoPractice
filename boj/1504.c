#include <stdio.h>

// floyd warshall algorithm

int n, e;

long long map[800][800];

void update(int start, int end, int mid) {
  if (map[start][mid] && map[mid][end]) {
    if (map[start][end] == 0
        || map[start][end] > (map[start][mid] + map[mid][end]))
      map[start][end] = map[start][mid] + map[mid][end];
  }
}

int main(void) {
  int start, end, weight, p1, p2;

  scanf("%d %d", &n, &e);
  for (int i = 0; i < e; ++i) {
    scanf("%d %d %d", &start, &end, &weight);
    if (map[start - 1][end - 1] == 0 || map[start - 1][end - 1] > weight) {
      map[start - 1][end - 1] = weight;
      map[end - 1][start - 1] = weight;
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        update(i, j, k);
      }
    }
  }

  scanf("%d %d", &p1, &p2);
  int a, b;
  if ((p1 == 1 || map[0][p1 - 1]) && map[p1 - 1][p2 - 1]
      && (p2 == n || map[p2 - 1][n - 1]))
    a = map[0][p1 - 1] + map[p1 - 1][p2 - 1] + map[p2 - 1][n - 1];
  else
    a = 0;

  if ((p2 == 1 || map[0][p2 - 1]) && map[p2 - 1][p1 - 1]
      && (p1 == n || map[p1 - 1][n - 1]))
    b = map[0][p2 - 1] + map[p2 - 1][p1 - 1] + map[p1 - 1][n - 1];
  else
    b = 0;

  if (a) {
    if (b)
      printf("%d\n", a < b ? a : b);
    else
      printf("%d\n", a);
  } else {
    if (b)
      printf("%d\n", b);
    else
      printf("-1\n");
  }

  return (0);
}
