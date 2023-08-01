#include <stdio.h>

/* fast IO */
char buff[1 << 20];

char
readChar(void) {
  static size_t idx = 1 << 20;
  if (idx == 1 << 20) {
    fread(buff, sizeof(char), 1 << 20, stdin);
    idx = 0;
  }
  return buff[idx++];
}

int
readInt(void) {
  int r;
  char c;
  do {
    c = readChar();
  } while (c < '0' || c > '9');
  r = 0;
  do {
    r = 10 * r + c - '0';
    c = readChar();
  } while (c >= '0' && c <= '9');
  return r;
}

#define MAX 1000001

char c[MAX]; /* check if composite number */
int p[MAX];  /* prime counting function   */

int
main(void) {
  int i, j, q, l, r;
  c[0] = c[1] = 1;
  p[0] = p[1] = 0;
  /* sieve */
  for (i = 2; i < MAX; ++i) {
    p[i] = p[i - 1];
    if (c[i])
      continue;
    ++p[i];
    for (j = 2; i * j < MAX; ++j)
      c[i * j] = 1;
  }
  q = readInt();
  while (q-- > 0) {
    l = readInt();
    r = readInt();
    printf("%d\n", p[2 * r - 1] - p[2 * l]);
  }
  return 0;
}

/* sum = (x + y)(y-x+1)/2 = prime */
/* 2 <= l <= x < y <= r           */
/* x+y=prime, y=x+1               */
