#include <stdio.h>

void test(void) {
  int n;
  int tot = 0;
  float sum = 0;
  int c;
  float g;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %f", &c, &g);
    tot += c;
    sum += g * c;
  }
  printf("%d %.1f\n", tot, (float)sum / tot);
}

int main(void) {
  int t;

  scanf("%d", &t);
  for (int i = 0; i < t; i++)
    test();
  return (0);
}
