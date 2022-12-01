#include <stdio.h>
#include <stdlib.h>

int n;
int arr[50];
int dp[50][50];

int max(int a, int b) {
  return (a > b ? a : b);
}

int cmp(const void* a, const void* b) {
  int x = *(int*)a;
  int y = *(int*)b;

  if (x > y)
    return (1);
  if (x < y)
    return (-1);
  return (0);
}

int solve(int start, int end) {
  if (start > end)
    return (0);
  if (dp[start][end] == 0) {
    if (start + 2 > end || arr[start] + arr[start + 1] > arr[end])
      dp[start][end] = end - start + 1;
    else
      dp[start][end] = max(solve(start + 1, end), solve(start, end - 1));
  }
  return (dp[start][end]);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);

  qsort(arr, n, sizeof(int), cmp);

  solve(0, n - 1);

  printf("%d\n", solve(0, n - 1));
  return (0);
}
