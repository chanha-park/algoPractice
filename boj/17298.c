#include <stdio.h>

typedef struct {
  int idx;
  int val;
} Elem;

Elem stack[1000000];
int NGE[1000000];

int main(void) {
  int n, x;
  int idx = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    NGE[i] = -1;
    while (idx > 0 && stack[idx - 1].val < x) {
      NGE[stack[idx - 1].idx] = x;
      --idx;
    }
    stack[idx++] = (Elem){i, x};
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", NGE[i]);
  }
  return (0);
}
