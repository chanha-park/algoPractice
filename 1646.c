#include <stdio.h>

long Fibo[51];

char path[100];
int idx;

long fibo(int n) {
  if (Fibo[n] == 0) {
    if (n <= 1)
      Fibo[n] = 1;
    else
      Fibo[n] = fibo(n - 1) + fibo(n - 2);
  }
  return (Fibo[n]);
}

void findPath(int n, const long s, const long e) {
  long piv;

  if (n <= 1)
    return;
  if (s == e)
    return;

  if (n == 2) {
    if (s != 1)
      path[idx++] = 'U';
    if (e != 1)
      path[idx++] = (e == 2 ? 'L' : 'R');
    return;
  }

  piv = (fibo(n - 2) << 1);

  if (s == 1) {
    if (e > piv) {
      path[idx++] = 'R';
      findPath(n - 1, 1, e - piv);
    } else {
      path[idx++] = 'L';
      findPath(n - 2, 1, e - 1);
    }
  } else if (e == 1) {
    if (s <= piv) {
      findPath(n - 2, s - 1, 1);
    } else {
      findPath(n - 1, s - piv, 1);
    }
    path[idx++] = 'U';
  } else {
    if (s <= piv && e <= piv) {
      findPath(n - 2, s - 1, e - 1);
    } else if (s > piv && e > piv) {
      findPath(n - 1, s - piv, e - piv);
    } else {
      if (s < e) {
        findPath(n - 2, s - 1, 1);
        path[idx++] = 'U';
        path[idx++] = 'R';
        findPath(n - 1, 1, e - piv);
      } else {
        findPath(n - 1, s - piv, 1);
        path[idx++] = 'U';
        path[idx++] = 'L';
        findPath(n - 2, 1, e - 1);
      }
    }
  }
}

int main(void) {
  int n;
  long s, e;
  scanf("%d %ld %ld", &n, &s, &e);
  findPath(n, s, e);
  path[idx] = '\0';
  printf("%s\n", path);
  return (0);
}
