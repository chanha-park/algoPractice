#include <stdio.h>

static const int ref[26] = {0, 0, 100, 500, 0, 0, 0, 0, 1, 0, 0,  50, 1000,
                            0, 0, 0,   0,   0, 0, 0, 0, 5, 0, 10, 0,  0};

int cal(char* str) {
  int ret = 0;
  while (*str && *str != '\n') {
    if (*str != ' ')
      ret += ref[*str - 'A'];
    ++str;
  }
  return (ret);
}

int main(void) {
  int t;
  char str[1002];
  scanf("%d", &t);
  getchar();
  while (t--) {
    fgets(str, 1002, stdin);
    printf("%d\n", cal(str));
  }
  return (0);
}
