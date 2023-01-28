#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

int main(void) {
  int n, m;
  int start, end;
  int tmp;
  int info[101] = {0};
  int visited[101] = {0};
  std::queue<std::pair<int, int> > que;

  std::cin >> n >> m;

  for (int i = 0; i < n + m; i++) {
    std::cin >> start >> end;
    info[start] = end;
  }
  que.push(std::make_pair(1, 0));
  visited[1] = 1;
  while (!que.empty()) {
    for (int i = 1; i <= 6; i++) {
      tmp = que.front().first + i;
      if (tmp <= 100 && visited[tmp] == 0) {
        while (info[tmp]) {
          visited[tmp] = 1;
          tmp = info[tmp];
        }
        visited[tmp] = 1;
        if (tmp == 100) {
          std::cout << que.front().second + 1 << std::endl;
          return (0);
        }
        que.push(std::make_pair(tmp, que.front().second + 1));
      }
    }
    que.pop();
  }
  return (0);
}
