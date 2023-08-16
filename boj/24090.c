#include <stdio.h>
#include <stdlib.h>

int m, k;

void
swap(int* arr, int a, int b) {
  int t;
  if (++m == k) {
    printf("%d %d", arr[b], arr[a]);
    exit(0);
  }
  t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

int
partition(int* arr, int begin, int end) {
  int i, j;
  const int piv = arr[end];
  for (i = begin - 1, j = begin; j < end; ++j) {
    if (arr[j] <= piv) {
      swap(arr, ++i, j);
    }
  }
  if (++i != end) {
    swap(arr, i, end);
  }
  return i;
}

void
sort(int* arr, int begin, int end) {
  if (begin < end) {
    const int mid = partition(arr, begin, end);
    sort(arr, begin, mid - 1);
    sort(arr, mid + 1, end);
  }
}

int
main(void) {
  int n, i;
  int arr[10000];
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr, 0, n - 1);
  printf("-1");
  return 0;
}
