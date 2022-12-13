#include <stdio.h>
#include <string.h>

char str[51];
int errflag;

void cover(char* s) {
  int i;

  while (*s == '.')
    s++;
  if (*s) {
    i = 0;
    while (s[i] == 'X')
      i++;
    if (i & 1) {
      errflag = 1;
      return;
    }
    memset(s, 'A', i & ~3);
    memset(s + (i & ~3), 'B', i & 3);
    cover(s + i);
  }
}

int main(void) {
  scanf("%s", str);
  cover(str);
  if (errflag)
    printf("-1\n");
  else
    printf("%s\n", str);
  return (0);
}
