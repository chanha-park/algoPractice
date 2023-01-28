#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

void test(void) {
  int k;
  int x;
  char c;
  std::multiset<int> q;

  std::cin >> k;

  for (int i = 0; i < k; i++) {
    std::cin >> c >> x;
    if (c == 'I')
      q.insert(x);
    else if (q.empty())
      continue;
    else if (x == -1)
      q.erase(q.begin());
    else
      q.erase(--q.end());
  }
  if (q.empty())
    std::cout << "EMPTY\n";
  else
    std::cout << *(--q.end()) << " " << *q.begin() << std::endl;
}

int main(void) {
  int t;

  std::cin >> t;

  for (int i = 0; i < t; i++)
    test();
}
