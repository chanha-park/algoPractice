#include <stdio.h>

int n;
int arr[50];
int a, b;

/*
 * arr[1] = a * arr[0] + b
 * arr[2] = a * arr[1] + b
 * arr[2] - arr[1] = a * (arr[1] - arr[0])
 */

int is_valid(void) {
  int diff0, diff1, i;

  diff0 = arr[1] - arr[0];
  diff1 = arr[2] - arr[1];
  if (diff0 == 0) {
    for (i = 1; i < n; ++i) {
      if (arr[i] != arr[i - 1])
        return (0);
    }
    a = 1;
    b = 0;
    return (1);
  }
  if (diff1 % diff0 != 0)
    return (0);
  a = diff1 / diff0;
  b = arr[1] - a * arr[0];
  for (i = 2; i < n; ++i) {
    if (arr[i] != a * arr[i - 1] + b)
      return (0);
  }
  return (1);
}

int main(void) {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  switch (n) {
    case (0):
      printf("A\n");
      break;
    case (1):
      printf("A\n");
      break;
    case (2):
      if (arr[0] == arr[1])
        printf("%d\n", arr[0]);
      else
        printf("A\n");
      break;
    default:
      if (is_valid())
        printf("%d\n", arr[n - 1] * a + b);
      else
        printf("B\n");
      break;
  }
  return (0);
}
