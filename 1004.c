#include <stdio.h>

int is_in(int x, int y, int r, int a, int b) {
  return ((a - x) * (a - x) + (b - y) * (b - y) < r * r);
}

void testcase(void) {
  int x_start, y_start, x_end, y_end, n, x_center, y_center, r;
  int count = 0;

  scanf("%d %d %d %d", &x_start, &y_start, &x_end, &y_end);
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d %d", &x_center, &y_center, &r);
    count += is_in(x_center, y_center, r, x_start, y_start) ^
             is_in(x_center, y_center, r, x_end, y_end);
  }
  printf("%d\n", count);
}

int main(void) {
  int t;

  scanf("%d", &t);
  while (t--)
    testcase();
  return (0);
}
