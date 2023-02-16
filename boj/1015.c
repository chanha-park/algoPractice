#include <stdio.h>

#define MAXN 50
#define RANGE 1001

int table[RANGE];
int mult[RANGE];

int
main(void) {
  int n;
  int arrA[MAXN];
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &arrA[i]);
    table[arrA[i]] += 1;
  }
  for (i = 1; i <= RANGE; ++i) {
    table[i] += table[i - 1];
  }
  for (i = 0; i < n; ++i) {
    printf("%d ", table[arrA[i] - 1] + mult[arrA[i]]);
    mult[arrA[i]] += 1;
  }
  printf("\n");
  return (0);
}
