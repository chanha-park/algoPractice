#include <iostream>
#include <list>
#include <queue>

enum {
  EMPTY,
  HOUSE,
  CHICKEN
};

int dist(int start, int end) {
  return (std::abs((start / 100) - (end / 100))
          + std::abs((start % 100) - (end % 100)));
}

struct Edge {
  int start;
  int end;
  int weight;

  Edge(int start, int end) : start(start), end(end), weight(dist(start, end)) {
  }

  bool operator<(const Edge& other) const {
    return (weight < other.weight);
  }
};

int map[50][50];
std::list<int> ho;
std::list<int> ch;
std::priority_queue<Edge> q;

int calcRisk(std::list<int>::iterator it) {
  return (*it);
}

int main(void) {
  int n, m, chCount;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> map[i][j];
      if (map[i][j] == CHICKEN)
        ch.push_back(100 * i + j);
      if (map[i][j] == HOUSE)
        ho.push_back(100 * i + j);
    }
  }

  chCount = ch.size();

  for (std::list<int>::iterator it = ho.begin(); it != ho.end(); ++it) {
    for (std::list<int>::iterator jt = ch.begin(); jt != ch.end(); ++jt) {
      q.push((Edge(*it, *jt)));
    }
  }

  std::cout << std::endl;

  int minRisk = 0x7fffffff;
  while ((int)ch.size() > m) {
    int tmp;
    std::list<int>::iterator minIt;
    for (std::list<int>::iterator jt = ch.begin(); jt != ch.end(); ++jt) {
      tmp = calcRisk(jt);
      if (minRisk > tmp) {
        minRisk = tmp;
        minIt = jt;
      }
    }
    ch.erase(minIt);
  }

  // while (!q.empty()) {
  //   std::cout << q.top().start << " " << q.top().end << " " << q.top().weight
  //             << std::endl;
  //   q.pop();
  // }
  return (0);
}
