#include <iostream>

int n;
int inOrder[100000];
int postOrder[100000];
int hashMap[100000];

void printPre(int startIn, int endIn, int startPost, int endPost) {
  int it = hashMap[postOrder[endPost - 1] - 1];

  std::cout << postOrder[endPost - 1] << " ";

  if (it > startIn)
    printPre(startIn, it, startPost, startPost + it - startIn);
  if (it + 1 < endIn)
    printPre(it + 1, endIn, startPost + it - startIn, endPost - 1);
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> inOrder[i];
    hashMap[inOrder[i] - 1] = i;
  }
  for (int i = 0; i < n; ++i)
    std::cin >> postOrder[i];

  printPre(0, n, 0, n);
  return (0);
}
