#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, k, t;
  std::cin >> n >> k;

  std::vector<int> v;
  for (int i = 0; i < n; ++i) {
    std::cin >> t;
    v.push_back(t);
  }

  std::sort(v.begin(), v.end());
  std::cout << v[k - 1] << "\n";

  return (0);
}
