#include <stdio.h>

void
test(int const n, int const m) {
  int i, j, calls[10000][2], s, d, c;
  for (i = 0; i < n; ++i) {
    scanf("%d %d", &calls[i][0], &calls[i][0]);
    scanf("%d %d", &calls[i][0], &calls[i][1]);
    calls[i][1] += calls[i][0];
  }
  for (i = 0; i < m; ++i) {
    scanf("%d %d", &s, &d);
    d += s;
    c = 0;
    for (j = 0; j < n; ++j) {
      if (d > calls[j][0] && s < calls[j][1])
        ++c;
    }
    printf("%d\n", c);
  }
}

int
main(void) {
  int n, m;
  while (scanf("%d %d", &n, &m) == 2 && !(n == 0 && m == 0)) {
    test(n, m);
  }
  return 0;
}
