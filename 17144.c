#include <stdio.h>

int map[50][50];
int next[50][50];
int r, c, t;
int clean1, clean2;
int totalDust;
static const int dx[] = {1, -1, 0, 0};
static const int dy[] = {0, 0, 1, -1};

void spreadDust(void) {
  int nx, ny, count, i, j, k;
  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j) {
      if (map[i][j] <= 0)
        continue;
      count = 0;
      for (k = 0; k < 4; ++k) {
        nx = i + dx[k];
        ny = j + dy[k];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] < 0)
          continue;
        ++count;
        next[nx][ny] += map[i][j] / 5;
      }
      map[i][j] -= (map[i][j] / 5) * count;
    }
  }

  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j) {
      map[i][j] += next[i][j];
      next[i][j] = 0;
    }
  }
}

int nx1(int x, int y) {
  if (x > 0 && y == 0)
    return (x - 1);
  if (x == 0 && y < c - 1)
    return (x);
  if (x < clean1 && y == c - 1)
    return (x + 1);
  return (x);
}

int ny1(int x, int y) {
  if (x > 0 && y == 0)
    return (y);
  if (x == 0 && y < c - 1)
    return (y + 1);
  if (x < clean1 && y == c - 1)
    return (y);
  return (y - 1);
}

int nx2(int x, int y) {
  if (x < r - 1 && y == 0)
    return (x + 1);
  if (x == r - 1 && y < c - 1)
    return (x);
  if (x > clean2 && y == c - 1)
    return (x - 1);
  return (x);
}

int ny2(int x, int y) {
  if (x < r - 1 && y == 0)
    return (y);
  if (x == r - 1 && y < c - 1)
    return (y + 1);
  if (x > clean2 && y == c - 1)
    return (y);
  return (y - 1);
}

void blowWind(void) {
  int nx, ny, i, j;
  totalDust -= map[clean1 - 1][0];
  for (i = clean1 - 1, j = 0; i != clean1 || j != 1;) {
    nx = nx1(i, j);
    ny = ny1(i, j);
    map[i][j] = map[nx][ny];
    i = nx;
    j = ny;
  }
  map[clean1][1] = 0;
  totalDust -= map[clean2 + 1][0];
  for (i = clean2 + 1, j = 0; i != clean2 || j != 1;) {
    nx = nx2(i, j);
    ny = ny2(i, j);
    map[i][j] = map[nx][ny];
    i = nx;
    j = ny;
  }
  map[clean2][1] = 0;
}

int main(void) {
  int i, j;
  scanf("%d %d %d", &r, &c, &t);
  for (i = 0; i < r; ++i) {
    for (j = 0; j < c; ++j) {
      scanf("%d", &map[i][j]);
      if (map[i][j] == -1) {
        if (clean1 != 0)
          clean2 = i;
        else
          clean1 = i;
      } else {
        totalDust += map[i][j];
      }
    }
  }
  while (t--) {
    spreadDust();
    blowWind();
  }
  printf("%d\n", totalDust);
  return (0);
}
