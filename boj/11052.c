#include <stdio.h>

int arr[1036];

int
main(void) {
  int a, b, idx, i, j;
  scanf("%d %d", &a, &b);
  idx = 1;
  for (i = 1; i < 45; ++i) {
    for (j = 0; j < i; ++j) {
      arr[idx] = arr[idx - 1] + i;
      idx++;
    }
  }
  printf("%d\n", arr[b] - arr[a - 1]);
  return (0);
}
