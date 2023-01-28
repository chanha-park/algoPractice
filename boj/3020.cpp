#include <algorithm>
#include <iostream>
#include <vector>

int hang[100000];
int hangIdx;
int rise[100000];
int riseIdx;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, h;
  std::cin >> n >> h;
  for (int i = 0; i < n; ++i) {
    if (i & 1)
      std::cin >> hang[hangIdx++];
    else
      std::cin >> rise[riseIdx++];
  }
  std::sort(hang, hang + hangIdx);
  std::sort(rise, rise + riseIdx);

  int minCount = n;
  int rangeCount = 0;
  int tmp;

  for (int i = 0; i < h; ++i) {
    tmp = n - (std::upper_bound(rise, rise + riseIdx, i) - rise)
          - (std::upper_bound(hang, hang + hangIdx, h - 1 - i) - hang);
    if (tmp < minCount) {
      minCount = tmp;
      rangeCount = 1;
    } else if (tmp == minCount) {
      rangeCount++;
    }
  }

  std::cout << minCount << " " << rangeCount << std::endl;
  return (0);
}
