#include <iostream>
#include <queue>
#include <string>

void testcase(void) {
  int n;
  std::string phoneNumber;
  std::string prev;
  std::string curr;
  std::priority_queue<std::string, std::vector<std::string>,
                      std::greater<std::string> >
      q;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> phoneNumber;
    q.push(phoneNumber);
  }

  while (!q.empty()) {
    prev = q.top();
    q.pop();
    if (!q.empty()) {
      curr = q.top();
      int i = 0;
      while (prev[i] && prev[i] == curr[i])
        ++i;
      if (prev[i] == '\0') {
        std::cout << "NO\n";
        return;
      }
    }
  }
  std::cout << "YES\n";
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int t;
  std::cin >> t;
  while (t--)
    testcase();
  return (0);
}
