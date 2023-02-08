#include <stdlib.h>
#include <iostream>

int n, m;

int** groups[4];

int state;

void
op1(void) {
  int** tmp;

  state = state + 6 - 4 * (state / 2);

  tmp = groups[0];
  groups[0] = groups[2];
  groups[2] = tmp;

  tmp = groups[1];
  groups[1] = groups[3];
  groups[3] = tmp;
}

void
op2(void) {
  int** tmp;

  state = (state + 4) % 8;

  tmp = groups[0];
  groups[0] = groups[1];
  groups[1] = tmp;

  tmp = groups[2];
  groups[2] = groups[3];
  groups[3] = tmp;
}

void
op3(void) {
  int** tmp;

  if (state < 4)
    state = (state + 1) % 4;
  else
    state = (state + 3) % 4 + 4;

  tmp = groups[0];
  groups[0] = groups[2];
  groups[2] = groups[3];
  groups[3] = groups[1];
  groups[1] = tmp;
}

void
op4(void) {
  int** tmp;

  if (state < 4)
    state = (state + 3) % 4;
  else
    state = (state + 1) % 4 + 4;

  tmp = groups[0];
  groups[0] = groups[1];
  groups[1] = groups[3];
  groups[3] = groups[2];
  groups[2] = tmp;
}

void
op5(void) {
  int** tmp;

  tmp = groups[0];
  groups[0] = groups[2];
  groups[2] = groups[3];
  groups[3] = groups[1];
  groups[1] = tmp;
}

void
op6(void) {
  int** tmp;

  tmp = groups[0];
  groups[0] = groups[1];
  groups[1] = groups[3];
  groups[3] = groups[2];
  groups[2] = tmp;
}

static void (*ops[6])(void) = {op1, op2, op3, op4, op5, op6};

void
print(void) {
  int i, j;

  if (state % 2 == 0) {
    for (i = 0; i < n * 2; ++i) {
      for (j = 0; j < m * 2; ++j) {
        std::cout << groups[(i / n) * 2 + (j / m)]
                           [state % 4 == 0 ? (i % n) : (n - 1 - i % n)]
                           [state % 6 == 0 ? (j % m) : (m - 1 - j % m)]
                  << " ";
      }
      std::cout << "\n";
    }

  } else {
    for (i = 0; i < m * 2; ++i) {
      for (j = 0; j < n * 2; ++j) {
        std::cout << groups[(i / m) * 2 + (j / n)]
                           [state % 6 != 1 ? (j % n) : (n - 1 - j % n)]
                           [state % 4 == 1 ? (i % m) : (m - 1 - i % m)]
                  << " ";
      }
      std::cout << "\n";
    }
  }
}

int
main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int r;
  int i, j;
  int op;
  std::cin >> n >> m >> r;
  n >>= 1;
  m >>= 1;

  for (i = 0; i < 4; ++i) {
    groups[i] = (int**)malloc(sizeof(int*) * n);
    for (j = 0; j < n; ++j) {
      groups[i][j] = (int*)malloc(sizeof(int) * m);
    }
  }

  for (i = 0; i < n * 2; ++i) {
    for (j = 0; j < m * 2; ++j) {
      std::cin >> groups[(i / n) * 2 + (j / m)][i % n][j % m];
    }
  }

  for (i = 0; i < r; ++i) {
    std::cin >> op;
    ops[op - 1]();
  }

  print();

  return (0);
}
