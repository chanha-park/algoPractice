#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int start;
  int end;
} line;

int cmp(const void* a, const void* b) {
  line x = *(line*)a;
  line y = *(line*)b;

  /* if (x.start == y.start) { */
  /*   if (x.end > y.end)      */
  /*     return (1);           */
  /*   if (x.end < y.end)      */
  /*     return (-1);          */
  /*   return (0);             */
  /* }                         */
  /* if (x.start > y.start)    */
  /*   return (1);             */
  /* return (-1);              */

  if (x.end == y.end) {
    if (x.start > y.start)
      return (1);
    if (x.start < y.start)
      return (-1);
    return (0);
  }
  if (x.end > y.end)
    return (1);
  return (-1);
}

int main(void) {
  int n;
  line lines[1000000];

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", &lines[i].start, &lines[i].end);
  qsort(lines, n, sizeof(line), cmp);
  for (int i = 0; i < n; i++)
    printf("start: %d, end: %d\n", lines[i].start, lines[i].end);

  return (0);
}
