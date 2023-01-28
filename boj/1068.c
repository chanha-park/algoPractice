#include <stdio.h>

typedef struct {
  int parent;
  int child[50];
  int childCount;
} Node;

Node node[50];
int n, toRemove;
int countLeaf;

int traversal(int root) {
  int flag = 0;
  int i;
  for (i = 0; i < node[root].childCount; ++i) {
    if (node[root].child[i] == toRemove)
      continue;
    flag |= traversal(node[root].child[i]);
  }
  if (flag == 0)
    countLeaf++;
  return (1);
}

int main(void) {
  int root, tmp, i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    node[i].parent = tmp;
    if (tmp == -1)
      root = i;
    else
      node[tmp].child[node[tmp].childCount++] = i;
  }
  scanf("%d", &toRemove);
  if (root != toRemove)
    traversal(root);
  printf("%d\n", countLeaf);
  return (0);
}
