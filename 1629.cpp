#include <cstdio>
#include <map>

std::map<int, long long> r;

long long f(int a, int b, int c) {
  long long k;

  std::map<int, long long>::iterator it = r.find(b);
  if (it != r.end())
    return (it->second);

  if (b == 1)
    k = a % c;
  else if (b & 1)
    k = (f(a, b / 2, c) * f(a, b / 2 + 1, c)) % c;
  else
    k = (f(a, b / 2, c) * f(a, b / 2, c)) % c;
  r.insert(std::make_pair(b, k));
  return (k);
}

int main(void) {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);
  printf("%lld\n", f(a, b, c));
  return (0);
}
