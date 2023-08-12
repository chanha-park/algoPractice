#include <stdio.h>

int
main(void) {
  int n, a, b;
  for (a = 1, scanf("%d", &n); n--;) {
    scanf("%d", &b);
    a += --b;
  }
  printf("%d", a);
  return 0;
}
