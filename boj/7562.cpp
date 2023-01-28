#include <iostream>
#include <queue>

struct Elem {
  int x;
  int y;
  int d;

  Elem(void) {
  }

  Elem(int x, int y, int d) : x(x), y(y), d(d) {
  }

  bool operator==(const Elem& other) {
    return (x == other.x && y == other.y);
  }
};

static const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
static const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void testcase(void) {
  int l;
  int startX, startY, endX, endY;
  std::queue<Elem> q;
  int visit[300][300] = {};

  std::cin >> l;
  std::cin >> startX >> startY;
  std::cin >> endX >> endY;

  if ((startX == endX) && (startY == endY)) {
    std::cout << "0\n";
    return;
  }

  visit[startX][startY] = 1;
  q.push(Elem(startX, startY, 0));

  Elem end(endX, endY, 0);

  Elem top;
  while (!q.empty()) {
    top = q.front();
    q.pop();
    for (int i = 0; i < 8; ++i) {
      Elem next(top.x + dx[i], top.y + dy[i], top.d + 1);
      if (next == end) {
        std::cout << next.d << "\n";
        return;
      }
      if (next.x < 0 || next.x >= l || next.y < 0 || next.y >= l)
        continue;
      if (visit[next.x][next.y])
        continue;
      visit[next.x][next.y] = 1;
      q.push(next);
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int t;
  std::cin >> t;
  while (t--)
    testcase();
  return (0);
}
