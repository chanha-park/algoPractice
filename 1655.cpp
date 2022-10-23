#include <iostream>
#include <set>

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, tmp;
  std::multiset<int> a;
  std::multiset<int> b;

  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;

    if (a.size() == b.size()) {
      if (b.size() > 0 && tmp > *b.begin()) {
        a.insert(*b.begin());
        b.erase(b.begin());
        b.insert(tmp);
      } else {
        a.insert(tmp);
      }
    } else {
      if (tmp < *a.rbegin()) {
        b.insert(*a.rbegin());
        a.erase(--a.end());
        a.insert(tmp);
      } else {
        b.insert(tmp);
      }
    }

    std::cout << *a.rbegin() << "\n";
  }

  return (0);
}
