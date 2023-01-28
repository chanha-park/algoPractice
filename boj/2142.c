#include <stdio.h>

int diff[500][500];

void testcase(void) {
  int n, m, prev, curr, flag;
  flag = 1;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &prev);
    for (int j = 1; j < m; ++j) {
      scanf("%d", &curr);
      diff[i][j] = curr - prev;
      if (i && diff[i][j] > diff[i - 1][j]) {
        flag = 0;
      }
      prev = curr;
    }
  }
  printf(flag ? "YES\n" : "NO\n");
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--)
    testcase();
  return (0);
}
