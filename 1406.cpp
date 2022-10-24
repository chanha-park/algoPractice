#include <iostream>
#include <list>
#include <string>

struct Editor {
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
};

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  Editor editor;
  std::string input, output;
  int m;
  char c;

  std::cin >> input;
  std::cin >> m;

  editor.text.insert(editor.text.begin(), input.begin(), input.end());

  editor.cursor = editor.text.end();
  while (m--) {
    std::cin >> c;
    switch (c) {
      case ('L'):
        editor.moveLeft();
        break;
      case ('D'):
        editor.moveRight();
        break;
      case ('B'):
        editor.deleteChar();
        break;
      case ('P'):
        std::cin >> c;
        editor.writeChar(c);
        break;
      default:
        break;
    }
  }
  output.insert(output.begin(), editor.text.begin(), editor.text.end());
  std::cout << output << "\n";
  return (0);
}
