#include <stdio.h>

int
main(void) {
  int n, i, j, k, m, s, x[35], y[35];
  scanf("%d", &n);
  m = 0;
  for (i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
    for (j = 0; j < i; ++j) {
      for (k = 0; k < j; ++k) {
        s = x[i] * y[j] + x[j] * y[k] + x[k] * y[i] - y[i] * x[j] - y[j] * x[k]
            - y[k] * x[i];
        if (s < 0)
          s = -s;
        if (m < s)
          m = s;
      }
    }
  }
  printf("%.1f\n", (double)m / 2);
  return 0;
}
