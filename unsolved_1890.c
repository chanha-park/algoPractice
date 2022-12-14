#include <stdio.h>

int n;
int board[100][100];
char visit[100][100];
int queue[10000][2];
int head;
int tail;
int count;

void
enque(int x, int y) {
  queue[tail][0] = x;
  queue[tail++][1] = y;
  tail %= n;
}

int
deque() {
  int tmp;
  tmp = queue[head][0] * 100 + queue[head][1];
  head = (head + 1) % n;
  return (tmp);
}

int
isValid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < n && !visit[x][y]);
}

int
main(void) {
  int x, y, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      scanf("%d", &board[i][j]);
  visit[0][0] = 1;
  enque(0, 0);
  while (head != tail) {
    x = deque();
    y = x % 100;
    x /= 100;
    if (isValid(x + board[x][y], y)) {
      if (x + board[x][y] == n - 1 && y == n - 1)
        count++;
      else {
        visit[x + board[x][y]][y] = 1;
        enque(x + board[x][y], y);
      }
    }
    if (isValid(x, board[x][y] + y)) {
      if (x == n - 1 && y + board[x][y] == n - 1)
        count++;
      else {
        visit[x][board[x][y] + y] = 1;
        enque(x, board[x][y] + y);
      }
    }
  }
  printf("%d\n", count);
  return (0);
}
