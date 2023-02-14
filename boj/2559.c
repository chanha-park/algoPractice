#include <stdio.h>
#include <stdlib.h>

char buff[500000];
int idx;

int
readInt(void) {
  int ret;
  int sign;
  while (buff[idx] == ' ')
    ++idx;

  ret = 0;
  sign = 1;
  if (buff[idx] == '-') {
    sign = -1;
    ++idx;
  }
  while ('0' <= buff[idx] && buff[idx] <= '9')
    ret = 10 * ret + buff[idx++] - '0';
  return (sign * ret);
}

int
main(void) {
  int n, k, sum, max;
  int i;
  int* arr;

  scanf("%d %d", &n, &k);
  arr = malloc(sizeof(int) * n);
  sum = 0;
  getchar();
  fgets(buff, 500000, stdin);
  for (i = 0; i < k; ++i) {
    arr[i] = readInt();
    sum += arr[i];
  }
  max = sum;
  for (i = k; i < n; ++i) {
    arr[i] = readInt();
    sum = sum - arr[i - k] + arr[i];
    if (max < sum)
      max = sum;
  }
  free(arr);
  printf("%d\n", max);
  return (0);
}
