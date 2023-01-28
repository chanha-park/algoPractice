#include <stdio.h>

unsigned long long fact_arr[21];

unsigned long long fact(int n) {
  if (fact_arr[n])
    return (fact_arr[n]);

  if (n < 2)
    fact_arr[n] = 1;
  else
    fact_arr[n] = fact(n - 1) * n;
  return (fact_arr[n]);
}

unsigned long long count;

void g(int tmp[],
       int visit[],
       int idx,
       const int n,
       const unsigned long long k) {
  if (count == k)
    return;

  if (idx == n) {
    count++;
    if (count == k) {
      for (int i = 0; i < n; i++)
        printf("%d ", tmp[i]);
      printf("\n");
    }
    return;
  }

  for (int i = 0; i < n; i++) {
    if (visit[i] == 0) {
      if (count + fact(n - idx - 1) < k)
        count += fact(n - idx - 1);
      else {
        visit[i] = 1;
        tmp[idx] = i + 1;
        g(tmp, visit, idx + 1, n, k);
        visit[i] = 0;
      }
    }
  }
}

unsigned long long ret = 1;

unsigned long long f(int arr[], int visit[], int idx, const int n) {
  if (idx == n)
    return (ret);

  for (int i = 0; i < n; i++) {
    if (visit[i])
      continue;
    if (arr[idx] == i + 1) {
      visit[i] = 1;
      break;
    }
    ret += fact(n - idx - 1);
  }

  return (f(arr, visit, idx + 1, n));
}

void test1(const int n) {
  unsigned long long k;
  scanf("%llu", &k);

  int tmp[21] = {0};
  int visit[21] = {0};
  g(tmp, visit, 0, n, k);
}

void test2(const int n) {
  int arr[21] = {0};
  int visit[21] = {0};
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("%lld\n", f(arr, visit, 0, n));
}

int main(void) {
  int n;
  scanf("%d", &n);

  int flag;
  scanf("%d", &flag);

  if (flag == 1) {
    test1(n);
  } else {
    test2(n);
  }
  return (0);
}
