#include <stdio.h>

int d[50];

int
main(void) {
  int r, c, i, j;
  char m[51];
  int result[9];
  scanf("%d %d", &r, &c);
  for (i = 0; i < r; ++i) {
    scanf("%s", m);
    for (j = c - 1; j >= 0; --j) {
      if (m[j] >= '1' && m[j] <= '9') {
        d[c - 2 - j] |= 1 << (m[j] - '1');
        break;
      }
    }
  }
  for (r = i = 0; i < c; ++i) {
    if (d[i]) {
      for (++r, j = 0; j < 9; ++j) {
        if (d[i] & (1 << j)) {
          result[j] = r;
        }
      }
    }
  }
  for (i = 0; i < 9; ++i) {
    printf("%d\n", result[i]);
  }
  return 0;
}
