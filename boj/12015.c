#include <stdio.h>
#include <stdlib.h>

int n;
int idx;

int
readInt(char* buff) {
  int ret;

  while (buff[idx] == ' ')
    ++idx;
  ret = 0;
  while (buff[idx] >= '0' && buff[idx] <= '9') {
    ret = 10 * ret + buff[idx] - '0';
    ++idx;
  }
  return (ret);
}

int
main(void) {
  int* arr;
  int* aux;
  char* buff;
  int len, newLen, left, right, mid;
  int i;
  scanf("%d", &n);
  getchar();
  arr = malloc(sizeof(int) * n);
  aux = malloc(sizeof(int) * (n + 1));
  buff = malloc(sizeof(char) * 8000010);

  fgets(buff, 8000010, stdin);
  for (i = 0; i < n; ++i)
    arr[i] = readInt(buff);

  len = 0;
  aux[0] = -1;

  for (i = 0; i < n; ++i) {
    left = 1;
    right = len + 1;
    while (left < right) {
      mid = (left + right) >> 1;
      if (arr[aux[mid]] >= arr[i])
        right = mid;
      else
        left = mid + 1;
    }

    newLen = left;
    aux[newLen] = i;

    if (newLen > len)
      len = newLen;
  }

  printf("%d\n", len);

  return (0);
}
