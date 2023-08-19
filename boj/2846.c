#include <stdio.h>

int
main(void) {
  int n;
  int h, i, start, curr, l, m;
  scanf("%d", &n);
  scanf("%d", &h);
  for (m = 0, l = 1, start = curr = h, i = 1; i < n; ++i) {
    scanf("%d", &h);
    if (h > curr) {
      ++l;
      if (l > 1)
        m = m > (h - start) ? m : (h - start);
    } else {
      l = 1;
      start = h;
    }
    curr = h;
  }
  printf("%d", m);
  return 0;
}
