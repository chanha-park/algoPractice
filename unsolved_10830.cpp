#include <iostream>
#include <map>

#define MOD 1000

std::map<int, int> dp;

struct mat {
  int size;
  int data[25];

};

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, b;
  int a[25];
  int ans[25];

  std::cin >> n >> b;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a.data[i * n + j];
    }
  }

  while (b > 1) {
    if (b & 1) {
    } else {
      matProd(a, a);
    }
    b >>= 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << a.data[i * n + j] << " ";
    }
    std::cout << "\n";
  }
  return (0);
}
