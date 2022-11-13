#include <stdio.h>
#include <string.h>

enum {
  FORWARD = 1,
  BACKWARD = 0
};

typedef struct string {
  char* content;
  char* start;
  char* end;
  int direction;
} string;

int isEmpty(string* x) {
  return (x->start == x->end);
}

int getLength(string* x) {
  if (x->direction == FORWARD)
    return (x->end - x->start + 1);
  else
    return (x->start - x->end + 1);
}

void removeA(string* x) {
  if (x->direction == FORWARD) {
    (x->end)--;
  } else {
    (x->end)++;
  }
}

void removeB(string* x) {
  char* tmp;

  if (x->direction == FORWARD) {
    (x->end)--;
  } else {
    (x->end)++;
  }
  tmp = x->end;
  x->end = x->start;
  x->start = tmp;
  x->direction ^= 1;
}

void reduce(string* x) {
  if (!isEmpty(x)) {
    if (*(x->end) == 'B')
      removeB(x);
    else
      removeA(x);
  }
}

int stringCmp(const char* s, string* x) {
  int step;
  char* curr;
  if (x->direction == FORWARD) {
    step = 1;
  } else {
    step = -1;
  }
  curr = x->start;
  while (*s && *s == *curr) {
    s++;
    curr += step;
  }
  return (*s == '\0');
}

int main(void) {
  char s[1001];
  char t[1001];
  string a;
  int sLen;
  scanf("%s", s);
  scanf("%s", t);

  a.content = t;
  a.start = a.content;
  a.end = a.start + strlen(t) - 1;
  a.direction = FORWARD;
  sLen = strlen(s);

  while (getLength(&a) > sLen)
    reduce(&a);
  printf("%d\n", stringCmp(s, &a));
  return (0);
}
