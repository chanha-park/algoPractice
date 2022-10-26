#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>

struct PhoneN {
  char nbr[11];
};

bool cmp(const PhoneN& a, const PhoneN& b) {
  return (std::strcmp(a.nbr, b.nbr) < 0);
}

void testcase(void) {
  int n;
  PhoneN phoneNumber;
  PhoneN prev;
  PhoneN curr;
  std::deque<PhoneN> q;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> phoneNumber.nbr;
    q.push_back(phoneNumber);
  }

  std::sort(q.begin(), q.end(), cmp);
  while (!q.empty()) {
    prev = q.front();
    q.pop_front();
    if (!q.empty()) {
      curr = q.front();
      int i = 0;
      while (prev.nbr[i] && prev.nbr[i] == curr.nbr[i])
        ++i;
      if (prev.nbr[i] == '\0') {
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
