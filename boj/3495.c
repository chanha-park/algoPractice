#include <stdio.h>

int
main(void) {
  int h, w, i, j, b, s;
  char note[100][101];
  scanf("%d %d", &h, &w);
  s = 0;
  for (i = 0; i < h; ++i) {
    b = 0;
    scanf("%s", note[i]);
    for (j = 0; j < w; ++j) {
      if (note[i][j] == '.') {
        s += b * 2;
      } else {
        s += 1;
        b = !b;
      }
    }
  }
  printf("%d", s / 2);
  return 0;
}
