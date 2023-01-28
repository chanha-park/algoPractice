#include <iostream>
#include <set>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n, tmp;

  std::cin >> n;

  std::set<int> a;

  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    a.insert(tmp);
  }
  for (std::set<int>::const_iterator it = a.begin(); it != a.end(); it++)
    std::cout << *it << " ";
  return (0);
}
