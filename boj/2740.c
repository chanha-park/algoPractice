#include <stdio.h>

/* matrix multiplication */

typedef struct {
  int data[100][100];
  int row;
  int col;
} Mat;

void getMat(Mat* x) {
  int i, j;

  scanf("%d %d", &x->row, &x->col);
  for (i = 0; i < x->row; ++i) {
    for (j = 0; j < x->col; ++j) {
      scanf("%d", &x->data[i][j]);
    }
  }
}

void printMat(Mat x) {
  int i, j;
  for (i = 0; i < x.row; ++i) {
    for (j = 0; j < x.col; ++j) {
      printf("%d ", x.data[i][j]);
    }
    printf("\n");
  }
}

Mat prodMat(Mat* a, Mat* b) {
  int i, j, k;
  Mat c;

  c.row = a->row;
  c.col = b->col;

  for (i = 0; i < c.row; ++i) {
    for (j = 0; j < c.col; ++j) {
      c.data[i][j] = 0;
      for (k = 0; k < b->row; ++k) {
        c.data[i][j] += a->data[i][k] * b->data[k][j];
      }
    }
  }
  return (c);
}

int main(void) {
  Mat a, b;

  getMat(&a);
  getMat(&b);
  printMat(prodMat(&a, &b));
  return (0);
}
