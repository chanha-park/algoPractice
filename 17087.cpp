#include <iostream>
#include <vector>

namespace boj {
int gcd(const int a, const int b) {
  if (a < 0)
    return (boj::gcd(-a, b));
  if (b < 0)
    return (boj::gcd(a, -b));
  if (a < b)
    return (boj::gcd(b, a));
  if (a % b == 0)
    return (b);
  return (boj::gcd(b, a % b));
}

int gcd(std::vector<int>& v) {
  if (v.size() == 1)
    return (*v.begin());

  int x = v.back();
  v.pop_back();
  int y = v.back();
  v.pop_back();
  v.push_back(boj::gcd(x, y));
  return (boj::gcd(v));
}
}  // namespace boj

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, s, x, d;
  std::cin >> n >> s;

  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    v.push_back(x - s);
  }
  d = boj::gcd(v);
  std::cout << d << "\n";
  return (0);
}
