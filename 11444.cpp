#include <iostream>
#include <map>

#define MOD 1000000007

typedef unsigned long long ull;

// sol1: fibonacci, use d'Ocagne's identity
// fibo(m + n) = fibo(m - 1) * f(n) + f(m) * f(n + 1)

// std::map<ull, ull> m;

// ull fibo(ull n) {
//   if (n <= 2)
//     return (n > 0);

//   std::map<ull, ull>::iterator it = m.find(n);
//   if (it == m.end()) {
//     ull a = n / 2;
//     ull b = n - a;

//     ull sum = (fibo(a + 1) * fibo(b)) % MOD;
//     sum += (fibo(a) * fibo(b - 1)) % MOD;
//     sum %= MOD;
//     m.insert(std::make_pair(n, sum));
//     return (sum);
//   } else
//     return (it->second);
// }

// sol2: use matrix
// a b
// c d

struct Mat {
  ull a, b, c, d;
  Mat(void) : a(1), b(1), c(1), d(0) {}
  Mat(ull a, ull b, ull c, ull d) : a(a), b(b), c(c), d(d) {}
  Mat(ull order) {
    if (order <= 1) {
      a = 1;
      b = (order == 1);
      c = b;
      d = (order != 1);
    } else if (order & 1) {
      Mat one;
      Mat half(order >> 1);
      *this = one.multiply(half.multiply(half));
    } else {
      Mat half(order >> 1);
      *this = half.multiply(half);
    }
  }
  Mat multiply(const Mat& other) {
    return (Mat(
        (a * other.a + b * other.c) % MOD, (a * other.b + b * other.d) % MOD,
        (c * other.a + d * other.c) % MOD, (c * other.b + d * other.d) % MOD));
  }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  ull n;
  std::cin >> n;

  Mat ret(n);

  std::cout << ret.b << "\n";
  return (0);
}
