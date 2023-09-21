#include <iostream>
#include <string>

int
main(void) {
  std::string toFind;
  int count = 0, t;
  std::cin >> toFind;
  std::cin >> t;
  while (t-- > 0) {
    std::string s;
    std::cin >> s;
    s += s;
    count += s.find(toFind) != std::string::npos;
  }
  std::cout << count;
  return 0;
}
