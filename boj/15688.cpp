#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, tmp;
  std::vector<int> v;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    v.push_back(tmp);
  }

  std::sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    std::cout << v[i] << "\n";
  }
  return (0);
}
