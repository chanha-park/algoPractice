#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  if (n == 1)
    printf("0\n");
  else
    printf("%d\n", (n * n + 1) >> 1);
  return (0);
}
