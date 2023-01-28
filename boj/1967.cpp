#include <iostream>
#include <vector>

struct Edge {
  int end;
  int weight;
  Edge(int c, int w) : end(c), weight(w) {}
};

typedef std::vector<Edge> Node;

int n, far, sum, max;

Node info[100000];
int visit[100000];

void dfs1(int start) {
  visit[start] = 1;
  if (sum > max) {
    max = sum;
    far = start;
  }
  for (std::vector<Edge>::iterator it = info[start].begin();
       it != info[start].end(); ++it) {
    if (visit[it->end])
      continue;
    sum += it->weight;
    dfs1(it->end);
    sum -= it->weight;
  }
}

void dfs2(int start) {
  visit[start] = 0;
  if (sum > max) {
    max = sum;
    far = start;
  }
  for (std::vector<Edge>::iterator it = info[start].begin();
       it != info[start].end(); ++it) {
    if (!visit[it->end])
      continue;
    sum += it->weight;
    dfs2(it->end);
    sum -= it->weight;
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int p, c, w;
  std::cin >> n;

  for (int i = 1; i < n; ++i) {
    std::cin >> p >> c >> w;
    info[p - 1].push_back(Edge(c - 1, w));
    info[c - 1].push_back(Edge(p - 1, w));
  }

  dfs1(0);
  dfs2(far);

  std::cout << max << "\n";
  return (0);
}
