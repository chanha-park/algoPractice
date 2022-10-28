#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node* next;
  int data;
} node;

node* head;
node* tail;
int size;

int n, m, count;

node* newNode(int k) {
  node* ret = malloc(sizeof(node));

  ret->next = NULL;
  ret->data = k;
  return (ret);
}

void enque(int k) {
  node* tmp = newNode(k);

  if (head) {
    tail->next = tmp;
  } else {
    head = tmp;
  }
  tail = tmp;
  size++;
}

void deque(void) {
  node* tmp = head;
  head = head->next;
  if (!head)
    tail = NULL;
  free(tmp);
  size--;
}

void rotate(void) {
  if (head && head->next) {
    node* tmp = head;
    head = head->next;
    tmp->next = NULL;
    tail->next = tmp;
    tail = tmp;
  }
}

int removeTarget(int target) {
  int diff = 0;

  while (head->data != target) {
    rotate();
    diff++;
  }
  if (diff > size - diff)
    diff = size - diff;

  deque();

  return (diff);
}

int main(void) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    enque(i + 1);
  }

  int target;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &target);
    count += removeTarget(target);
  }

  printf("%d\n", count);
  while (size > 0)
    deque();
  return (0);
}
