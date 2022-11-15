#include <iostream>
#include <queue>

struct Ice {
  int x, y;

  Ice(void) {
  }

  Ice(int x, int y) : x(x), y(y) {
  }
};

int map[300][300];
int toMelt[300][300];
int visit[300][300];
std::queue<Ice> q;
int count, t;
int n, m, flag;
static const int dx[] = {1, -1, 0, 0};
static const int dy[] = {0, 0, 1, -1};

void melt(void) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      visit[i][j] = 0;
      map[i][j] -= toMelt[i][j];
      toMelt[i][j] = 0;
    }
  }
}

void bfs(void) {
  Ice tmp;
  int nx, ny, diff;
  while (!q.empty()) {
    tmp = q.front();
    q.pop();
    diff = 0;
    for (int i = 0; i < 4; ++i) {
      nx = tmp.x + dx[i];
      ny = tmp.y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (map[nx][ny] <= 0)
        continue;
      ++diff;
      if (visit[nx][ny])
        continue;
      visit[nx][ny] = 1;
      q.push(Ice(nx, ny));
    }
    toMelt[tmp.x][tmp.y] = 4 - diff;
  }
}

void oneYear(void) {
  count = 0;
  flag = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (visit[i][j] == 0 && map[i][j] > 0) {
        flag = 1;
        visit[i][j] = 1;
        q.push(Ice(i, j));
        ++count;
        bfs();
      }
    }
  }
  ++t;
  melt();
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> map[i][j];
    }
  }
  flag = 1;
  while (count < 2 && flag)
    oneYear();

  if (flag)
    std::cout << t - 1 << "\n";
  else
    std::cout << "0\n";
  return (0);
}
