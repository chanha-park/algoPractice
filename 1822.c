#include <stdio.h>

/* binary search, bsearch, qsort quicksort implementation */

int na, nb;
int a[500000];
int b[500000];
int diff[500000];
int count;

int partition(int* base, int start, int end) {
  int piv = base[(start + end) / 2];
  int left = start;
  int right = end - 1;
  int tmp;
  while (1) {
    while (base[left] < piv)
      ++left;
    while (base[right] > piv)
      --right;
    if (left >= right)
      return (right);
    if (base[left] == base[right])
      ++left;
    else {
      tmp = base[left];
      base[left] = base[right];
      base[right] = tmp;
    }
  }
}

void sort(int* base, int start, int end) {
  if (start + 1 >= end)
    return;
  int mid = partition(base, start, end);
  sort(base, start, mid);
  sort(base, mid + 1, end);
}

int* search(int key, int* base, int len) {
  int left = 0;
  int right = len;
  int mid;

  while (left < right) {
    mid = (left + right) / 2;
    if (base[mid] < key)
      left = mid + 1;
    else if (base[mid] > key)
      right = mid;
    else
      return (base + mid);
  }
  return (NULL);
}

int main(void) {
  scanf("%d %d", &na, &nb);
  for (int i = 0; i < na; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < nb; ++i)
    scanf("%d", &b[i]);
  sort(a, 0, na);
  sort(b, 0, nb);
  for (int i = 0; i < na; ++i) {
    if (!search(a[i], b, nb))
      diff[count++] = a[i];
  }
  printf("%d\n", count);
  for (int i = 0; i < count; ++i)
    printf("%d ", diff[i]);
  return (0);
}
