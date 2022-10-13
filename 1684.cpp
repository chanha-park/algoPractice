#include <cstdio>
#include <cstdlib>
#include <vector>

namespace boj {
int gcd(const int a, const int b) {
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
  int n, x, prev, d;
  scanf("%d", &n);

  std::vector<int> v;
  scanf("%d", &prev);
  for (int i = 1; i < n; i++) {
    scanf("%d", &x);
    if (x != prev)
      v.push_back(std::abs(x - prev));
    prev = x;
  }
  d = boj::gcd(v);
  printf("%d\n", d);
  return (0);
}
