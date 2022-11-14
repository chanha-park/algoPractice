#include <iostream>

#define INF 100000000

int n;

struct Map {
  int* map;
  int n;

  Map(int n) : n(n) {
    map = new int[n * n];
    for (int i = 0; i < n * n; ++i) {
      map[i] = INF;
    }
  }

  ~Map(void) {
    delete[] map;
  }
};

int isConnected(Map& map, int start, int end) {
  return (start == end || map.map[start * n + end] != 0);
}

int update(Map& map, int start, int end, int mid) {
  if (map.map[start * n + end]
      > map.map[start * n + mid] + map.map[mid * n + end]) {
    map.map[start * n + end]
        = map.map[start * n + mid] + map.map[mid * n + end];
  }
  return (start == end && map.map[start * n + end] < 0);
}

void testcase(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int m, w, s, e, t;
  std::cin >> n >> m >> w;
  Map map(n);
  for (int i = 0; i < m; ++i) {
    std::cin >> s >> e >> t;
    if (map.map[(s - 1) * n + (e - 1)] > t)
      map.map[(s - 1) * n + (e - 1)] = t;
    if (map.map[(e - 1) * n + (s - 1)] > t)
      map.map[(e - 1) * n + (s - 1)] = t;
  }
  for (int i = 0; i < w; ++i) {
    std::cin >> s >> e >> t;
    if (map.map[(s - 1) * n + (e - 1)] > -t)
      map.map[(s - 1) * n + (e - 1)] = -t;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (update(map, i, j, k)) {
          std::cout << "YES\n";
          return;
        }
      }
    }
  }

  std::cout << "NO\n";
}

int main(void) {
  int tc;
  std::cin >> tc;
  while (tc--)
    testcase();
  return (0);
}
