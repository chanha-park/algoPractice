#include <iostream>

#define MAX 1000000

int info[1000][1000];

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m, x, s, e, t;
  std::cin >> n >> m >> x;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j)
        info[i][j] = MAX;
      else
        info[i][j] = 0;
    }
  }

  for (int i = 0; i < m; ++i) {
    std::cin >> s >> e >> t;
    info[s - 1][e - 1] = t;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (info[i][j] > info[i][k] + info[k][j])
          info[i][j] = info[i][k] + info[k][j];
      }
    }
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    if (info[i][x - 1] + info[x - 1][i] > ans)
      ans = info[i][x - 1] + info[x - 1][i];
  }
  std::cout << ans;
  return (0);
}
