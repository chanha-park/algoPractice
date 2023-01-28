#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> v;
long n, d;

long
calc(void) {
  long sum = 0;
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
    sum = sum * d + *it;
  }
  return (sum);
}

int
main(void) {
  std::cin >> n >> d;

  for (int i = 0; i < d; ++i)
    v.push_back(i);
  v[0] = 1;
  v[1] = 0;

  long num = calc();
  while (num <= n && std::next_permutation(v.begin(), v.end()))
    num = calc();
  if (num > n)
    std::cout << num << "\n";
  else
    std::cout << "-1\n";

  return (0);
}
