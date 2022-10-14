#include <deque>
#include <iostream>
#include <queue>

int n;

int map[20][20];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct Node {
  int x;
  int y;
  int depth;

  Node(void) : x(0), y(0), depth(0) {
  }

  Node(int x, int y, int depth) : x(x), y(y), depth(depth) {
  }
};

namespace boj {

template <typename T>
struct comp {
  bool operator()(T& a, T& b) {
    if (a.depth != b.depth)
      return (a.depth > b.depth);
    if (a.x != b.x)
      return (a.x > b.x);
    return (a.y > b.y);
  }
};

}  // namespace boj

struct Shark {
  int size;
  int x;
  int y;
  int time;
  int exp;

  Shark(void) : size(2), x(0), y(0), time(0), exp(0) {
  }

  int gotoTarget(void) {
    int visit[20][20] = {{0}};
    int xnext, ynext;
    std::priority_queue<Node, std::deque<Node>, boj::comp<Node> > q;
    Node p;

    visit[x][y] = 1;
    q.push(Node(x, y, 0));
    while (!q.empty()) {
      p = q.top();
      q.pop();

      if (map[p.x][p.y] && map[p.x][p.y] < size) {
        exp++;
        if (exp == size) {
          size++;
          exp = 0;
        }
        x = p.x;
        y = p.y;
        map[p.x][p.y] = 0;
        time += p.depth;
        return (1);
      }

      for (int i = 0; i < 4; i++) {
        xnext = p.x + dx[i];
        ynext = p.y + dy[i];
        if (xnext < 0 || ynext < 0 || xnext >= n || ynext >= n
            || visit[xnext][ynext] || map[xnext][ynext] > size)
          continue;

        visit[xnext][ynext] = 1;
        q.push(Node(xnext, ynext, p.depth + 1));
      }
    }

    return (0);
  }
};

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n;

  Shark s;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> map[i][j];
      if (map[i][j] == 9) {
        s.x = i;
        s.y = j;
        map[i][j] = 0;
      }
    }
  }

  while (s.gotoTarget()) {
  }

  std::cout << s.time << "\n";

  return (0);
}
