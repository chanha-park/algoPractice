#include <stdio.h>

int arr[100001];
char buff[600000];
int idx;

/* use fgets for fast IO */
int getInt(void) {
  int ret = 0;

  while (buff[idx] == ' ')
    idx++;
  while (buff[idx] >= '0' && buff[idx] <= '9') {
    ret = 10 * ret + buff[idx++] - '0';
  }
  return (ret);
}

int main(void) {
  int n, s, left, right, len;
  scanf("%d %d", &n, &s);
  getchar();
  fgets(buff, 6 * n, stdin);
  for (int i = 1; i <= n; ++i) {
    arr[i] = getInt() + arr[i - 1];
  }
  if (arr[n] < s) {
    printf("0\n");
    return (0);
  }
  left = 0;
  right = 0;
  len = n;
  while (left <= right && right <= n) {
    if (arr[right] - arr[left] < s) {
      ++right;
    } else {
      len = (right - left < len) ? (right - left) : len;
      ++left;
    }
  }

  printf("%d\n", len);

  return (0);
}
