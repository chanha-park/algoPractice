#include <stdio.h>

int n, count;
char s[100001];
char stack[100001];
int idx;

int isGoodWord(char* s) {
  idx = 0;
  while (*s) {
    if (idx && stack[idx - 1] == *s)
      idx--;
    else
      stack[idx++] = *s;
    s++;
  }
  return (idx == 0);
}

int main(void) {
  scanf("%d", &n);
  count = 0;

  while (n--) {
    scanf("%s", s);
    count += isGoodWord(s);
  }

  printf("%d\n", count);
  return (0);
}
