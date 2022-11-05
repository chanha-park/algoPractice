#include <iostream>
#include <queue>

std::queue<long long> q;
bool check[10];

#define CHECK(x)    \
  if (f(x)) {       \
    std::cout << x; \
    return (0);     \
  }

void toCheck(int n) {
  while (n > 0) {
    check[n % 10] = true;
    n /= 10;
  }
}

bool f(long long n) {
  for (int div = 2; div < 10; ++div) {
    if (check[div] && n % div)
      return (false);
  }
  return (true);
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  long long ans;
  std::cin >> n;

  toCheck(n);

  CHECK(n)
  q.push(n);
  while (true) {
    ans = q.front();
    q.pop();
    for (int i = 0; i < 10; ++i) {
      CHECK(10 * ans + i)
      q.push(10 * ans + i);
    }
  }

  return (0);
}
