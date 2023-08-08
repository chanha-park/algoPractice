#include <stdio.h>
#include <stdlib.h>

void
test(void) {
  int g, i, s[300], m;
  char* a;
  scanf("%d", &g);
  for (i = 0; i < g; ++i) {
    scanf("%d", &s[i]);
  }
  if (g == 1) {
    printf("1\n");
    return;
  }
  for (m = 2;; ++m) {
    a = calloc(m, sizeof(char));
    for (i = 0; i < g; ++i) {
      if (a[s[i] % m])
        break;
      a[s[i] % m] = 1;
    }
    free(a);
    if (i == g) {
      printf("%d\n", m);
      return;
    }
  }
}

int
main(void) {
  int n;
  scanf("%d", &n);
  while (n-- > 0) {
    test();
  }
  return 0;
}
