#include <stdio.h>
#include <string.h>

char broken[100];

int
main(void) {
  int n, m, x, y, count, i;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 0; i < m; ++i) {
    scanf("%d %d", &x, &y);
    memset(broken + (x - 1), 1, y - x);
  }
  count = 0;
  for (i = 0; i < n; ++i)
    count += broken[i];
  printf("%d\n", n - count);
  return (0);
}
