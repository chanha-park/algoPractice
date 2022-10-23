#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, tmp;
  std::priority_queue<int, std::vector<int>, std::less<int> > a;
  std::priority_queue<int, std::vector<int>, std::greater<int> > b;

  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;

    if (a.size() == b.size()) {
      if (b.size() > 0 && tmp > b.top()) {
        a.push(b.top());
        b.pop();
        b.push(tmp);
      } else {
        a.push(tmp);
      }
    } else {
      if (tmp < a.top()) {
        b.push(a.top());
        a.pop();
        a.push(tmp);
      } else {
        b.push(tmp);
      }
    }

    std::cout << a.top() << "\n";
  }

  return (0);
}
