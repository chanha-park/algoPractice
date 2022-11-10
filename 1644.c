#include <stdio.h>

int primeArr[500000];
long long sumArr[500000];
int primeCnt;
int n;

int isPrime(int k) {
  for (int i = 0; i < primeCnt && (primeArr[i] <= k / primeArr[i]); ++i) {
    if (k % primeArr[i] == 0)
      return (0);
  }
  return (1);
}

void setArr(void) {
  primeArr[primeCnt++] = 2;
  sumArr[primeCnt] = 2;
  for (int i = 3; i <= n; ++i) {
    if (isPrime(i)) {
      primeArr[primeCnt++] = i;
      sumArr[primeCnt] = i + sumArr[primeCnt - 1];
    }
  }
}

int main(void) {
  scanf("%d", &n);

  setArr();
  int left = 0;
  int right = 0;
  int count = 0;
  while (left <= right && right <= primeCnt) {
    if (sumArr[right] - sumArr[left] < (long long)n) {
      ++right;
    } else {
      if (sumArr[right] - sumArr[left] == (long long)n)
        ++count;
      ++left;
    }
  }
  printf("%d\n", count);
  return (0);
}
