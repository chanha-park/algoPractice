#include <stdio.h>

int
main(void) {
  long a, b, c;
  scanf("%ld %ld %ld", &a, &b, &c);
  if (a + b == c)
    printf("1\n");
  else if (a * a + b * b == c * c)
    printf("2\n");
  else
    printf("-1\n");
  return (0);
}
