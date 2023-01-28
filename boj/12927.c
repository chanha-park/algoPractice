#include <stdio.h>

int len, count;
char str[1001];

int
main(void) {
  int i, j;
  scanf("%s", str);
  while (str[len])
    len++;

  for (i = 1; i <= len; ++i) {
    if (str[i - 1] == 'Y') {
      count++;
      for (j = 1; j * i <= len; ++j)
        str[i * j - 1] = 167 - str[i * j - 1];
    }
  }
  printf("%d\n", count);
  return (0);
}
