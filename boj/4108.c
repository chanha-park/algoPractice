#include <stdio.h>

int
d(char (*field)[101], int i, int j, int r, int c) {
  static const int a[] = {1, 1, 1, 0, 0, -1, -1, -1};
  static const int b[] = {1, 0, -1, 1, -1, 1, 0, -1};
  int k, t;
  t = 0;
  for (k = 0; k < 8; ++k) {
    t += (i + a[k]) >= 0 && (i + a[k]) < r && (j + b[k]) >= 0 && (j + b[k]) < c
         && field[i + a[k]][j + b[k]] == '*';
  }
  return t;
}

int
main(void) {
  int r, c, i, j;
  char field[100][101];
  while (scanf("%d %d", &r, &c) == 2 && r != 0) {
    for (i = 0; i < r; ++i) {
      scanf("%s", field[i]);
    }
    for (i = 0; i < r; ++i) {
      for (j = 0; j < c; ++j) {
        if (field[i][j] == '.')
          field[i][j] = d(field, i, j, r, c) + '0';
      }
    }
    for (i = 0; i < r; ++i) {
      printf("%s\n", field[i]);
    }
  }
  return 0;
}
