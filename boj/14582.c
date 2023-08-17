#include <stdio.h>

int
main(void) {
  int a[18], i, x;
  for (i = 0; i < 9; ++i) {
    scanf("%d", &a[2 * i]);
  }
  for (i = 0; i < 9; ++i) {
    scanf("%d", &a[2 * i + 1]);
    a[2 * i + 1] *= -1;
  }
  for (x = i = 0; x <= 0 && i < 18; ++i) {
    x += a[i];
  }
  puts(x > 0 ? "Yes" : "No");
  return 0;
}
