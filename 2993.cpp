#include <iostream>
#include <set>
#include <string>

std::string str;
int len;

std::string
flip(std::string orig, int p1, int p2) {
  char tmp;
  for (int left = 0, right = p1 - 1; left < right; ++left, (void)--right) {
    tmp = orig[left];
    orig[left] = orig[right];
    orig[right] = tmp;
  }
  for (int left = p1, right = p2 - 1; left < right; ++left, (void)--right) {
    tmp = orig[left];
    orig[left] = orig[right];
    orig[right] = tmp;
  }
  for (int left = p2, right = len - 1; left < right; ++left, (void)--right) {
    tmp = orig[left];
    orig[left] = orig[right];
    orig[right] = tmp;
  }
  return (orig);
}

int
main(void) {
  std::cin >> str;
  std::set<std::string> s;
  len = str.size();

  s.insert(str);
  for (int i = 1; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      s.insert(flip(str, i, j));
    }
  }
  std::cout << *s.begin() << std::endl;
  return (0);
}
