#include <stdio.h>

char input[1000000];

int main(void) {
  int count, i;
  scanf("%s", input);
  count = 1;
  for (i = 1; input[i]; ++i) {
    if (input[i] != input[i - 1])
      ++count;
  }
  printf("%d\n", count >> 1);
  return (0);
}
