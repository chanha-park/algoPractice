#include <stdio.h>

void swap(int* a, int* b) {
  int tmp;
  if (*a < *b) {
    tmp = *a;
    *a = *b;
    *b = tmp;
  }
}

int main(void) {
  int x1, x2, x3, y1, y2, y3, a, b, c, det;

  scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
  det = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
  if (det == 0) {
    printf("X");
    return (0);
  }
  a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
  c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
  swap(&b, &c);
  swap(&a, &b);
  swap(&b, &c);
  if (b == c) {
    if (a == b) {
      printf("JungTriangle");
    } else if (a > b + c) {
      printf("Dunkak2Triangle");
    } else if (a < b + c) {
      printf("Yeahkak2Triangle");
    } else {
      printf("Jikkak2Triangle");
    }

  } else {
    if (a == b) {
      printf("Yeahkak2Triangle");
    } else if (a > b + c) {
      printf("DunkakTriangle");
    } else if (a < b + c) {
      printf("YeahkakTriangle");
    } else {
      printf("JikkakTriangle");
    }
  }
  return (0);
}
