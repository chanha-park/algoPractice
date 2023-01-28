#include <stdio.h>

int
main(void) {
  long n;
  scanf("%ld", &n);
  printf((n % 7 != 2 && n % 7 != 0) ? "SK\n" : "CY\n");
  return (0);
}
