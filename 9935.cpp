#include <iostream>
#include <stack>
#include <string>

int main(void) {
  std::string orig, bomb, s;
  // size_t pos = 0;

  std::cin >> orig;
  std::cin >> bomb;

  size_t count = 0;

  std::string::iterator it = orig.begin();

  while (it != orig.end()) {
    s.push_back(*it);
    ++it;
  }

  if (s.length())
    std::cout << s << "\n";
  else
    std::cout << "FRULA\n";
  return (0);
}
