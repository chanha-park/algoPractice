#include <stdio.h>

int
main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d", n <= m ? (2 * n - 2) : (2 * m - 1));
  return 0;
}
