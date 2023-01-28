#include <stdio.h>

int stack[80000];
int size;
long sum;

int main(void) {
  int n, h, i;

  scanf("%d", &n);
  i = 0;
  while (i < n) {
    scanf("%d", &h);
    while (size > 0 && stack[size - 1] <= h)
      --size;
    stack[size++] = h;
    sum += size - 1;
    ++i;
  }

  printf("%ld\n", sum);
  return (0);
}
