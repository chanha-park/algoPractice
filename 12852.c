#include <stdio.h>

int dp[1000000];

int stack[500];

int f(int n) {
  if (n <= 1) {
    return (0);
  }
  if (dp[n - 1] == 0) {
    int a = f(n / 2) + n % 2 + 1;
    int b = f(n / 3) + n % 3 + 1;
    dp[n - 1] = (a < b ? a : b);
  }
  return (dp[n - 1]);
}

void fill(int n, int idx) {
  stack[idx++] = n;

  if (n == 1)
    return;

  if (n % 2) {
    if (n % 3) {
      fill(n - 1, idx);
    } else {
      int a = f(n - 1);
      int b = f(n / 3);
      fill((a < b ? (n - 1) : (n / 3)), idx);
    }
  } else {
    if (n % 3) {
      int a = f(n - 1);
      int b = f(n / 2);
      fill((a < b ? (n - 1) : (n / 2)), idx);
    } else {
      int a = f(n - 1);
      int b = f(n / 2);
      int c = f(n / 3);
      int next = n - 1;
      if (a > b) {
        next = n / 2;
        a = b;
      }
      if (a > c) {
        next = n / 3;
        a = c;
      }
      fill(next, idx);
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);

  stack[0] = n;
  int ans = f(n);
  fill(n, 0);
  printf("%d\n", ans);

  for (int i = 0; i <= ans; ++i) {
    printf("%d ", stack[i]);
  }
  return (0);
}
