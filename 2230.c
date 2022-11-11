#include <stdio.h>

int arr[100000];

/* quicksort implementation */
int partition(int start, int end) {
  int piv, left, right, tmp;

  piv = arr[(start + end) / 2];
  left = start;
  right = end - 1;
  while (1) {
    while (arr[left] < piv)
      ++left;
    while (arr[right] > piv)
      --right;
    if (left >= right)
      return (right);
    if (arr[left] == arr[right])
      ++left;
    else {
      tmp = arr[left];
      arr[left] = arr[right];
      arr[right] = tmp;
    }
  }
}

void sort(int start, int end) {
  int mid;

  if (start + 1 >= end)
    return;
  mid = partition(start, end);
  sort(start, mid);
  sort(mid + 1, end);
}

int main(void) {
  int n, m, left, right, min, i;

  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(0, n);

  left = 0;
  right = 0;
  min = 2000000000;
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
