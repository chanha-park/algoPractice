#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>

#define MOD 1000000000000000000LL

typedef unsigned long long ll;

long long f(std::map<double, ll>& m, double n) {
  if (n <= M_PI)
    return (1);

  const std::map<double, ll>::iterator it = m.find(n);
  if (it != m.end())
    return (it->second);

  std::pair<double, ll> p
      = std::make_pair<double, ll>(n, (f(m, n - 1) + f(m, n - M_PI)) % MOD);

  m.insert(p);
  return (p.second);
}

int main(void) {
  int n;
  std::map<double, ll> m;

  scanf("%d", &n);
  printf("%lld\n", f(m, n));

  return (0);
}
