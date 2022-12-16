#include <stdio.h>

#define SIZE 1000000

typedef struct {
  int x, y;
} point;

int n, m, t, count;
unsigned char info[1000][1000];
unsigned char visit[1000][1000];

point q[SIZE];
int head, tail;

void
enque(int x, int y) {
  q[tail].x = x;
  q[tail].y = y;
  tail = (tail + 1) % SIZE;
}

point
deque(void) {
  point tmp;
  tmp = q[head];
  head = (head + 1) % SIZE;
  return (tmp);
}

static const int dx[4] = {1, -1, 0, 0};
static const int dy[4] = {0, 0, 1, -1};

void
bfs(int x, int y) {
  point top;
  int nx, ny, i;
  count++;
  visit[x][y] = 1;
  enque(x, y);
  while (head != tail) {
    top = deque();
    for (i = 0; i < 4; ++i) {
      nx = top.x + dx[i];
      ny = top.y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] == 1)
        continue;
      if (info[nx][ny] < t)
        continue;
      visit[nx][ny] = 1;
      enque(nx, ny);
    }
  }
}

int
main(void) {
  int r, g, b, i, j;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      scanf("%d %d %d", &r, &g, &b);
      info[i][j] = ((r + g + b) / 3);
    }
  }
  scanf("%d", &t);

  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (visit[i][j] == 0 && info[i][j] >= t)
        bfs(i, j);
    }
  }
  printf("%d\n", count);
  return (0);
}
