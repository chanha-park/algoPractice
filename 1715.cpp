#include <iostream>
#include <queue>

int n, x, y;
long long sum;
std::priority_queue<int, std::deque<int>, std::greater<int> > q;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    q.push(x);
  }

  while (q.size() > 1) {
    x = q.top();
    q.pop();
    y = q.top();
    q.pop();
    sum += (x + y);
    q.push(x + y);
  }

  std::cout << sum << "\n";
  return (0);
}
