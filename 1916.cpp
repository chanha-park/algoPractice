#include <deque>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 21474836

// dijkstra

namespace boj {

template <typename T>
struct comp {
  bool operator()(T& a, T& b) {
    return (a.second > b.second);
  }
};

}  // namespace boj

std::vector<std::pair<int, int> > info[20000];
int ans[20000];

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, m;
  int x, y, z;

  std::cin >> n;
  std::cin >> m;

  for (int i = 0; i < n; i++)
    ans[i] = MAX;

  for (int i = 0; i < m; i++) {
    std::cin >> x >> y >> z;
    info[x - 1].push_back(std::make_pair(y - 1, z));
  }

  int start, end;
  std::cin >> start >> end;

  std::priority_queue<std::pair<int, int>,
                      std::deque<std::pair<int, int> >,
                      boj::comp<std::pair<int, int> > >
      q;

  q.push(std::make_pair(start - 1, 0));

  std::pair<int, int> tmp;

  int next, newDist;

  while (!q.empty()) {
    tmp = q.top();
    q.pop();
    if (ans[tmp.first] < tmp.second)
      continue;
    for (size_t i = 0; i < info[tmp.first].size(); i++) {
      next = info[tmp.first][i].first;
      newDist = tmp.second + info[tmp.first][i].second;
      if (newDist < ans[next]) {
        ans[next] = newDist;
        q.push(std::make_pair(next, newDist));
      }
    }
  }

  std::cout << ans[end - 1] << "\n";
  return (0);
}
