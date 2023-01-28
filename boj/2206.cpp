#include <iostream>
#include <queue>

struct Elem {
  int x;
  int y;
  int d;
  bool canBreak;
  Elem(void) {}
  Elem(int x, int y, int d, bool canBreak)
      : x(x), y(y), d(d), canBreak(canBreak) {}
};

char map[1001][1001];
bool visit[1001][1001][2];
std::queue<Elem> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> map[i];
  }

  if (n == 1 && m == 1) {
    std::cout << "1\n";
    return (0);
  }

  Elem t;
  int nx, ny;

  visit[0][0][true] = true;
  q.push(Elem(0, 0, 1, true));

  while (!q.empty()) {
    t = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      nx = t.x + dx[i];
      ny = t.y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny][t.canBreak])
        continue;
      if (map[nx][ny] == '0') {
        if (nx == (n - 1) && ny == (m - 1)) {
          std::cout << t.d + 1 << "\n";
          return (0);
        }
        visit[nx][ny][t.canBreak] = true;
        q.push(Elem(nx, ny, t.d + 1, t.canBreak));
      } else if (t.canBreak) {
        visit[nx][ny][!t.canBreak] = true;
        q.push(Elem(nx, ny, t.d + 1, false));
      } else
        continue;
    }
  }

  std::cout << "-1\n";

  return (0);
}
