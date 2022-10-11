#include <algorithm>
#include <climits>
#include <cstdio>

int main(void) {
  int v[100000];
  int n, m, diff;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  std::sort(v, v + n);
  m = INT_MIN;
  for (int i = 1; i + 1 < n; i++) {
    diff = v[i - 1] + v[n - 1] - (v[i] << 1);
    if (diff < 0)
      diff = -diff;
    if (diff > m)
      m = diff;
    diff = v[0] + v[i + 1] - (v[i] << 1);
    if (diff < 0)
      diff = -diff;
    if (diff > m)
      m = diff;
  }
  printf("%d\n", m);
  return (0);
}
