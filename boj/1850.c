#include <stdio.h>
#include <string.h>
#include <unistd.h>

char s[10000001];

int main(void) {
  long a, b, c;
  scanf("%ld %ld", &a, &b);
  c = a % b;
  while (c) {
    a = b;
    b = c;
    c = a % b;
  }
  memset(s, '1', b);
  write(1, s, b);
  return (0);
}
