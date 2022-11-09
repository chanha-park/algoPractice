#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
  int x = *(int*)a;
  int y = *(int*)b;

  if (x > y)
    return (1);
  if (x < y)
    return (-1);
  return (0);
}

int arr[100000];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  qsort(arr, n, sizeof(int), cmp);

  int left = 0;
  int right = 0;
  int min = 2000000000;
  while (right < n && left <= right) {
    if (arr[right] - arr[left] < m) {
      ++right;
    } else {
      if (arr[right] - arr[left] < min)
        min = arr[right] - arr[left];
      ++left;
    }
  }
  printf("%d\n", min);
  return (0);
}
