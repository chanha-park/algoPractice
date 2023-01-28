#include <stdio.h>

typedef struct {
  int height;
  long n;
} People;

People stack[500000];
int size;
long count;

int main(void) {
  int n, h, i;
  scanf("%d", &n);

  for (i = 0; i < n; ++i) {
    scanf("%d", &h);

    while (size > 0 && stack[size - 1].height < h) {
      --size;
      count += (stack[size].n * (stack[size].n + 1)) / 2;
      if (size > 0)
        count += stack[size].n;
    }
    if (size > 0 && stack[size - 1].height == h)
      stack[size - 1].n += 1;
    else {
      stack[size].height = h;
      stack[size].n = 1;
      ++size;
    }
  }
  while (size > 1) {
    count += (stack[size - 1].n * (stack[size - 1].n + 1)) / 2;
    --size;
  }
  if (size)
    count += (stack[size - 1].n * (stack[size - 1].n - 1)) / 2;
  printf("%ld\n", count);
  return (0);
}
