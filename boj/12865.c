#include <stdio.h>

// knapsack

typedef struct {
  int weight;
  int value;
} Item;

Item info[101];

int dp[101][100001];

int findMax(int count, int maxWeight) {
  if (count == 0)
    return (0);

  if (dp[count][maxWeight])
    return (dp[count][maxWeight]);

  if (info[count].weight > maxWeight) {
    dp[count][maxWeight] = findMax(count - 1, maxWeight);
    return (dp[count][maxWeight]);
  }

  int a = findMax(count - 1, maxWeight);
  int b =
      findMax(count - 1, maxWeight - info[count].weight) + info[count].value;

  dp[count][maxWeight] = (a > b ? a : b);
  return (dp[count][maxWeight]);
}

int main(void) {
  int n, k;

  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &info[i + 1].weight, &info[i + 1].value);
  }

  printf("%d\n", findMax(n, k));
  return (0);
}

/*

#include <stdio.h>

int dp[100001];

int main(void) {
  int curr, k, n, w, v;

  scanf("%d %d", &n, &k);

  while (n--) {
    scanf("%d %d", &w, &v);

    for (curr = k; curr >= w; --curr) {
      if (dp[curr] < dp[curr - w] + v) {
        dp[curr] = dp[curr - w] + v;
      }
    }
  }

  printf("%d", dp[k]);

  return (0);
}

*/
