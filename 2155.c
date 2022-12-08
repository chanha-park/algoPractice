#include <stdio.h>

typedef struct {
  int row;
  int col;
} triangle;

triangle* goLeft(triangle* tr) {
  tr->col--;
  return (tr);
}

triangle* goRight(triangle* tr) {
  tr->col++;
  return (tr);
}

triangle* goDown(triangle* tr) {
  tr->row++;
  tr->col++;
  return (tr);
}

int sq(int n) {
  int root;
  if (n == 0)
    return (0);
  root = 1;
  while (root <= n / root)
    root++;
  return (root - 1);
}

triangle numToTriangle(int n) {
  triangle tr;
  tr.row = sq(n);
  tr.col = n - tr.row * tr.row;
  return (tr);
}

int path(triangle* a, triangle* b) {
  if (a->row < b->row) {
    if (a->col & 1) {
      if (a->col < b->col)
        return (1 + path(goRight(a), b));
      return (1 + path(goLeft(a), b));
    } else
      return (1 + path(goDown(a), b));
  } else {
    if (a->col > b->col)
      return (a->col - b->col);
    return (b->col - a->col);
  }
}

int main(void) {
  int a, b;
  triangle x, y;

  scanf("%d %d", &a, &b);
  if (a < b) {
    x = numToTriangle(a - 1);
    y = numToTriangle(b - 1);
  } else {
    y = numToTriangle(a - 1);
    x = numToTriangle(b - 1);
  }
  printf("%d\n", path(&x, &y));
  return (0);
}
