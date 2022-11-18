#include <iostream>
#include <queue>

enum {
  RIGHT = 0,
  UP,
  LEFT,
  DOWN
};

enum {
  EMPTY = 0,
  APPLE,
  SNAKE
};

int n;
char map[100][100];
std::queue<std::pair<int, char> > moveQue;
int playTime;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

struct Snake {
  std::queue<std::pair<int, int> > q;
  int dir;
  bool alive;

  Snake(void) : dir(RIGHT), alive(true) {
  }

  void move(void) {
    ++playTime;
    int nx = q.back().first + dx[dir];
    int ny = q.back().second + dy[dir];
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
      alive = false;
      return;
    }
    switch (map[nx][ny]) {
      case (SNAKE):
        alive = false;
        return;
      case (APPLE):
        map[nx][ny] = SNAKE;
        q.push(std::make_pair(nx, ny));
        break;
      default:
        map[nx][ny] = SNAKE;
        q.push(std::make_pair(nx, ny));
        map[q.front().first][q.front().second] = EMPTY;
        q.pop();
        break;
    }
    if (!moveQue.empty() && playTime == moveQue.front().first) {
      if (moveQue.front().second == 'D')
        dir = (dir + 3) % 4;
      else
        dir = (dir + 1) % 4;
      moveQue.pop();
    }
  }

  bool isAlive(void) const {
    return (alive);
  }
};

int main(void) {
  int k, x, y, l, t;
  char c;
  Snake snake;

  std::cin >> n;
  std::cin >> k;
  for (int i = 0; i < k; ++i) {
    std::cin >> x >> y;
    map[x - 1][y - 1] = APPLE;
  }
  std::cin >> l;
  for (int i = 0; i < l; ++i) {
    std::cin >> t >> c;
    moveQue.push(std::make_pair(t, c));
  }
  map[0][0] = SNAKE;
  snake.q.push(std::make_pair(0, 0));
  while (snake.isAlive())
    snake.move();
  std::cout << playTime << std::endl;
  return (0);
}
