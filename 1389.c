#include <stdio.h>

#define INF 1147483647

int main(void) {
  int n, m;

  scanf("%d %d", &n, &m);

  int a, b;
  int relation[100][100];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j)
        relation[i][j] = 0;
      else
        relation[i][j] = INF;
    }

  for (int i = 0; i < m; i++) {
	  scanf("%d %d", &a, &b);
    relation[a - 1][b - 1] = 1;
    relation[b - 1][a - 1] = 1;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (relation[i][j] - relation[i][k] > relation[k][j]) {
          relation[i][j] = relation[i][k] + relation[k][j];
          relation[j][i] = relation[i][j];
        }
      }
    }
  }

  int sum, min = INF, ans = -1;
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < n; j++) {
      sum += relation[i][j];
    }
    if (sum < min) {
      min = sum;
      ans = i;
    }
  }

  printf("%d\n", ans + 1);
  return (0);
}
