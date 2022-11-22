#include <iostream>
#include <map>

int n, m;
int arr[8];
int visit[8];
std::map<int, int> ref;
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
  for (std::map<int, int>::iterator it = ref.begin(); it != ref.end(); ++it) {
    if (it->second == 0)
      continue;
    it->second -= 1;
    arr[idx++] = it->first;
    dfs();
    --idx;
    it->second += 1;
  }
}

int main(void) {
  int tmp;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    if (ref.find(tmp) == ref.end())
      ref.insert(std::make_pair(tmp, 1));
    else
      ref[tmp] += 1;
  }
  dfs();
  return (0);
}
