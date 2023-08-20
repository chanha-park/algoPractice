#include <stdio.h>

int
main(void) {
  int i, a, b;
  scanf("%d %d", &a, &b);
  i = 0;
  printf("%d.", a / b);
  do {
    a %= b;
    a *= 10;
    printf("%d", a / b);
  } while (i++ < 1000);
  return 0;
}
