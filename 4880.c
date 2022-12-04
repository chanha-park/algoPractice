#include <stdio.h>

int main(void) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  while (a != 0 || b != 0 || c != 0) {
    if (a + c == 2 * b)
      printf("AP %d\n", 2 * c - b);
    else
      printf("GP %d\n", (c * c) / b);
    scanf("%d %d %d", &a, &b, &c);
  }
  return (0);
}
