#include <stdio.h>

int arr[100001];

int f(int n, int k) {
  if (arr[k] != 0)
    return (arr[k]);
  if (n >= k) {
    arr[k] = n - k;
    return (n - k);
  }

  int a = 1 + f(n, (k > 1) ? k - 1 : 0);
  int c = ((k & 1) == 0) ? f(n, k >> 1) : 200000;
  if (a > c)
    a = c;

  if ((k & 1) && k < 100000 && k != 1) {
    int b = 1 + f(n, (k + 1) >> 1);
    if (a > b)
      a = b;
  }

  arr[k] = a;
  return (a);
}

int main(void) {
  int n, k;

  scanf("%d %d", &n, &k);
  printf("%d\n", f(n, k));
  return (0);
}
