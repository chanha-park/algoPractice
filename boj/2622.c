#include <stdio.h>

int
main(void) {
  int n;
  scanf("%d", &n);
  n += n % 2 ? 3 : 0;
  printf("%d", (n * n + 24) / 48);
  return 0;
}
