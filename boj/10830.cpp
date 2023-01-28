#include <iostream>
#include <map>

#define MOD 1000

int n;

struct mat {
  int data[25];
};

std::map<long long, mat> dp;

mat matProd(const mat& a, const mat& b) {
  mat c;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c.data[i * n + j] = 0;
      for (int k = 0; k < n; k++)
        c.data[i * n + j] += a.data[i * n + k] * b.data[k * n + j];
      c.data[i * n + j] %= MOD;
    }
  }

  return (c);
}

mat matMod(const mat& a) {
  mat c;

  for (int i = 0; i < n * n; i++)
    c.data[i] = a.data[i] % MOD;
  return (c);
}

mat matPow(const mat& a, long long b) {
  if (b == 1)
    return (matMod(a));

  std::map<long long, mat>::iterator it = dp.find(b);
  if (it != dp.end())
    return (it->second);

  mat c = matProd(matPow(a, b / 2), matPow(a, b / 2));
  if (b & 1)
    c = matProd(c, a);
  dp.insert(std::make_pair(b, c));
  return (c);
}

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  long long b;
  mat a;
  mat ans;

  std::cin >> n >> b;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a.data[i * n + j];
    }
  }
  ans = matPow(a, b);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << ans.data[i * n + j] << " ";
    }
    std::cout << "\n";
  }
  return (0);
}
