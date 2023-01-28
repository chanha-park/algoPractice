#include <stdio.h>

int is_broken(const int broken[], int n) {
  if (n == 0)
    return (broken[0]);

  while (n > 0) {
    if (broken[n % 10]) {
      return (1);
    }

    n /= 10;
  }
  return (0);
}

int digits(int n) {
  if (n == 0)
    return (1);

  int count = 0;

  while (n > 0) {
    count++;
    n /= 10;
  }
  return (count);
}

int main(void) {
  int broken[10] = {0};

  int n, m, tmp, count, min;

  scanf("%d", &n);
  scanf("%d", &m);

  for (int i = 0; i < m; i++) {
    scanf("%d", &tmp);
    broken[tmp] = 1;
  }

  min = 10000000;
  for (int i = 0; i <= n; i++) {
    if (!is_broken(broken, n - i)) {
      count = digits(n - i) + i;
      if (min > count)
        min = count;
      break;
    }
  }

  for (int i = 0; i < 1000000; i++) {
    if (!is_broken(broken, n + i)) {
      count = digits(n + i) + i;
      if (min > count)
        min = count;
      break;
    }
  }

  int a = n > 100 ? n - 100 : 100 - n;
  printf("%d\n", min < a ? min : a);
  return (0);
}
