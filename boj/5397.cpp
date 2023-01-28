#include <iostream>
#include <list>
#include <string>

struct Logger {
  std::list<char> text;
  std::list<char>::iterator cursor;

  void moveLeft(void) {
    if (cursor == text.begin())
      return;
    --cursor;
  }

  void moveRight(void) {
    if (cursor == text.end())
      return;
    ++cursor;
  }

  void deleteChar(void) {
    if (cursor == text.begin())
      return;
    --cursor;
    cursor = text.erase(cursor);
  }

  void writeChar(char c) {
    cursor = text.insert(cursor, c);
    ++cursor;
  }

  void copyText(char* output) const {
    for (std::list<char>::const_iterator it = text.begin(); it != text.end();
         ++it) {
      *output++ = *it;
    }
    *output = '\0';
  }
};

char input[1000001];
char output[1000001];

void testcase(void) {
  Logger logger;

  std::cin >> input;
  logger.cursor = logger.text.end();

  for (int i = 0; input[i]; ++i) {
    switch (input[i]) {
      case ('<'):
        logger.moveLeft();
        break;
      case ('>'):
        logger.moveRight();
        break;
      case ('-'):
        logger.deleteChar();
        break;
      default:
        logger.writeChar(input[i]);
        break;
    }
  }

  logger.copyText(output);
  std::cout << output << "\n";
}

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int t;

  std::cin >> t;

  while (t--)
    testcase();
  return (0);
}
