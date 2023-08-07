#include <stdio.h>
#include <stdlib.h>

int
cmp(const void* a, const void* b) {
  return *(const int*)a > *(const int*)b ? 1 : -1;
}

int
main(void) {
  int n, m, i, j, c, s;
  int arr[15000];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  qsort(arr, n, sizeof(int), cmp);
  c = 0;
  for (i = 0, j = n - 1; i < j;) {
    s = arr[i] + arr[j];
    if (s > m)
      --j;
    else if (s < m)
      ++i;
    else {
      ++c;
      ++i;
      --j;
    }
  }
  printf("%d", c);
  return 0;
}
