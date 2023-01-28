#include <iostream>
#include <set>

int n, m;
int arr[8];
int visit[8];
std::set<int> ref;
int idx;

void print(void) {
  for (int i = 0; i < m; ++i)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

void dfs(void) {
  if (idx == m) {
    print();
    return;
  }
  for (std::set<int>::iterator it = ref.begin(); it != ref.end(); ++it) {
    if (idx && arr[idx - 1] > *it)
      continue;
    arr[idx++] = *it;
    dfs();
    --idx;
  }
}

int main(void) {
  int tmp;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    ref.insert(tmp);
  }
  dfs();
  return (0);
}
