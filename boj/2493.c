#include <stdio.h>

typedef struct {
  int height;
  int id;
} tower;

tower stack[500001];
int idx;

void push(int h, int i) {
  stack[idx++] = (tower){h, i};
}

tower pop(void) {
  return (stack[--idx]);
}

tower top(void) {
  return (stack[idx - 1]);
}

int isEmpty(void) {
  return (idx == 0);
}

void printLeft(int x) {
  while (!isEmpty() && top().height < x) {
    pop();
  }
  printf("%d ", top().id);
}

int main(void) {
  int n, x;

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    printLeft(x);
    push(x, i + 1);
  }
  return (0);
}
