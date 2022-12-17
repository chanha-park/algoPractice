#include <stdio.h>

unsigned char data[236197];

int
power(int base, int order) {
  int ret;
  ret = 1;
  while (order--)
    ret *= base;
  return (ret);
}

int
next(int curr, int p) {
  int ret;
  ret = 0;
  while (curr > 0) {
    ret += power(curr % 10, p);
    curr /= 10;
  }
  return (ret);
}

int
main(void) {
  int a, p, idx;
  scanf("%d %d", &a, &p);
  idx = 1;
  while (data[a] == 0) {
    printf("a: %d\n", a);
    data[a] = idx++;
    a = next(a, p);
  }
  printf("a: %d\n", a);
  printf("%d\n", data[a] - 1);
  return (0);
}
