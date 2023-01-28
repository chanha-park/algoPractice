#include <stdio.h>

int countSegment(char* input) {
  int level = 0;
  int count = 0;
  char prev = '\0';

  while (*input) {
    if (*input == '(') {
      level++;
    } else {
      level--;
      if (prev == '(')
        count += level;
      else
        count += 1;
    }
    prev = *input++;
  }
  return (count);
}

int main(void) {
  char input[100001];
  scanf("%s", input);
  printf("%d\n", countSegment(input));
  return (0);
}
