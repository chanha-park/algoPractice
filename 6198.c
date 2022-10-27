#include <stdio.h>

int stack[80000];
int size;
long long sum;

int main(void) {
  int n, h;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h);
    while (size > 0 && stack[size - 1] <= h)
      --size;
    stack[size++] = h;
    sum += size - 1;
  }

  printf("%lld\n", sum);
  return (0);
}
