#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

typedef struct list {
  struct list* next;
  node* value;
} list;

struct node {
  node* parent;
  list* connect;
  int idx;
};

list* new_list(node* value) {
  list* ret = malloc(sizeof(list));

  ret->next = NULL;
  ret->value = value;
  return (ret);
}

void add_connect(node* arr, int x, int y) {
  list* curr;

  curr = new_list(&arr[y]);
  curr->next = arr[x].connect;
  arr[x].connect = curr;

  curr = new_list(&arr[x]);
  curr->next = arr[y].connect;
  arr[y].connect = curr;
}

void set_parent(node* root, node* paren) {
  if (!root)
    return;

  root->parent = paren;

  list* curr = root->connect;

  while (curr) {
    if (curr->value != paren)
      set_parent(curr->value, root);
    curr = curr->next;
  }
}

int main(void) {
  int n, x, y;

  scanf("%d", &n);

  node* arr = calloc(n, sizeof(node));

  for (int i = 0; i < n - 1; i++) {
    arr[i].idx = i + 1;
    scanf("%d %d", &x, &y);
    add_connect(arr, x - 1, y - 1);
  }
  arr[n - 1].idx = n;

  set_parent(&arr[0], NULL);

  for (int i = 1; i < n; i++)
    printf("%d\n", arr[i].parent->idx);

  for (int i = 0; i < n; i++) {
    list* curr = arr[i].connect;
    list* tmp;

    while (curr) {
      tmp = curr;
      curr = curr->next;
      free(tmp);
    }
  }
  free(arr);

  return (0);
}
