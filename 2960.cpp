#include <iostream>
#include <list>

int main(void) {
  int n, k, p, q;
  std::list<int> l;
  std::cin >> n >> k;
  for (int i = 2; i <= n; ++i) {
    l.push_back(i);
  }
  while (!l.empty()) {
    p = l.front();
    l.pop_front();
    --k;
    if (k == 0) {
      std::cout << p << std::endl;
      return (0);
    }
    for (std::list<int>::iterator it = l.begin(); it != l.end();) {
      q = *it;
      if (q % p == 0) {
        l.erase(it);
        it = l.begin();
        --k;
        if (k == 0) {
          std::cout << q << std::endl;
          return (0);
        }
      } else
        ++it;
    }
  }
  return (0);
}
