#include <algorithm>
#include <iostream>
#include <vector>

int n;
std::vector<int> v;

bool isPossible(int idx) {
  if (idx == 0)
    return (false);

  int target = v[idx];

  for (int i = 0; i < idx; ++i) {
    for (int j = idx - 1; j >= i; --j) {
      if (v[i] + v[j] >= target)
        continue;
      if (std::binary_search(
              v.begin() + j, v.begin() + idx, target - v[i] - v[j]))
        return (true);
    }
  }
  return (false);
}

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n;
  int x;
  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    v.push_back(x);
  }
  std::sort(v.begin(), v.end());

  int idx = n - 1;
  while (idx >= 0 && !isPossible(idx))
    --idx;
  std::cout << v[idx] << "\n";

  return (0);
}
