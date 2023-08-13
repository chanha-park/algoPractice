#include <stdio.h>

int
main(void) {
  int h, w, i, c;
  char sky[101];
  scanf("%d %d", &h, &w);
  while (h-- > 0) {
    scanf("%s", sky);
    for (c = -1, i = 0; i < w; ++i) {
      if (sky[i] == 'c')
        c = 0;
      else if (c >= 0)
        ++c;
      printf("%d ", c);
    }
    printf("\n");
  }
  return 0;
}
