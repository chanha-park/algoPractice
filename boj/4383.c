#include <stdio.h>

int
main(void) {
  int n, s, t, i;
  while (scanf("%d", &n) == 1) {
    char arr[3000] = {0};
    scanf("%d", &s);
    for (i = 1; i < n; ++i) {
      scanf("%d", &t);
      arr[t > s ? t - s : s - t] = 1;
      s = t;
    }
    for (i = 1; i < n && arr[i]; ++i)
      ;
    printf(i == n ? "Jolly\n" : "Not jolly\n");
  }
  return 0;
}
