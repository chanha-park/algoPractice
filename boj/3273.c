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

int arr[1000001];

int main(void) {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &x);

  qsort(arr, n, sizeof(int), cmp);

  int left = 0;
  int right = n - 1;
  int count = 0;
  int sum;

  while (left < right) {
    sum = arr[left] + arr[right];
    count += (sum == x);
    if (sum > x)
      --right;
    else if (sum <= x)
      ++left;
  }

  printf("%d\n", count);

  return (0);
}
