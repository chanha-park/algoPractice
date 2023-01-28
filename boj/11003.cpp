#include <deque>
#include <iostream>

struct node {
  int index;
  int value;
};

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, l, x;
  std::cin >> n >> l;
  std::deque<node> d;

  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    if (!d.empty() && i - d.front().index >= l)
      d.pop_front();
    while (!d.empty() && d.back().value > x)
      d.pop_back();
    d.push_back((node){i, x});
    std::cout << d.front().value << " ";
  }
  return (0);
}
