#include <math.h>
#include <stdio.h>
#include <string.h>

char from[10001];
char to[10001];

int
main(void) {
  int t, len, idx, i, j;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", from);
    len = sqrt(strlen(from));
    idx = 0;
    for (i = len - 1; i >= 0; --i) {
      for (j = 0; j < len; ++j) {
        to[idx++] = from[i + len * j];
      }
    }
    to[idx] = '\0';
    printf("%s\n", to);
  }
  return (0);
}
