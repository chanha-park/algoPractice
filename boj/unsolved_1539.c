#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node* left;
  struct Node* right;
  unsigned long long value;
  /* unsigned long long height; */
} Node;

unsigned long long totalHeight;

Node* newNode(unsigned long long k) {
  Node* ret = malloc(sizeof(Node));

  ret->left = NULL;
  ret->right = NULL;
  ret->value = k;
  /* ret->height = h; */
  return (ret);
}

void insertNode(Node** root, unsigned long long k, unsigned long long h) {
  if (*root) {
    if ((*root)->value < k)
      insertNode(&((*root)->left), k, h + 1);
    else
      insertNode(&((*root)->right), k, h + 1);
  } else {
    *root = newNode(k);
    totalHeight += h;
  }
}

int main(void) {
  int n, tmp;
  Node* root = NULL;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    insertNode(&root, tmp, 1);
  }

  printf("%llu\n", totalHeight);

  return (0);
}
