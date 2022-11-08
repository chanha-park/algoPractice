#include <stdio.h>
#include <string.h>

int n;
char buff[1000];

int main(void) {
  int i;
  scanf("%d", &n);
  if (n > 1)
    memset(buff, ' ', 2 * n - 3);
  printf("%.*s*\n", n - 1, buff);
  for (i = 1; i < n; i++) {
    printf("%.*s*%.*s*\n", n - i - 1, buff, 2 * i - 1, buff);
  }
  return (0);
}
