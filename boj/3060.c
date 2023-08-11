#include <stdio.h>

int
main(void) {
  int t, n, s, i, j;
  for (scanf("%d", &t); t > 0; --t) {
    scanf("%d", &n);
    for (s = i = 0; i < 6; ++i) {
      scanf("%d", &j);
      s += j;
    }
    for (i = 1; s <= n; ++i, s *= 4)
      ;
    printf("%d\n", i);
  }
  return 0;
}
