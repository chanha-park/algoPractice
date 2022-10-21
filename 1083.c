#include <stdio.h>

int s;
int offset;

void movePossibleMax(int* a, int n) {
  int max = a[0];
  int maxIdx = 0;
  int tmp;

  for (int i = 0; i < n && i <= s; i++) {
    if (max < a[i]) {
      max = a[i];
      maxIdx = i;
    }
  }

  for (int i = maxIdx; i > 0; i--) {
    tmp = a[i];
    a[i] = a[i - 1];
    a[i - 1] = tmp;
  }
  s -= maxIdx;
}

int main(void) {
  int n;
  int a[50];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &s);

  while (s > 0 && offset < n) {
    movePossibleMax(a + offset, n - offset);
    offset++;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  return (0);
}
