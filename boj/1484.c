#include <stdio.h>

int arr[100];
int idx;

int main(void) {
  int g, i;
  scanf("%d", &g);

  for (i = 1; i < g / i; ++i) {
    if (g % i == 0 && (g / i - i) % 2 == 0) {
      arr[idx++] = (g / i + i) / 2;
    }
  }
  if (idx == 0)
    printf("-1\n");
  else {
    for (i = idx; i > 0; --i) {
      printf("%d\n", arr[i - 1]);
    }
  }
  return (0);
}
