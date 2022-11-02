#include <stdio.h>

int n;
int inOrder[100000];
int postOrder[100000];

// naive recursion
void printPre(int startIn, int endIn, int startPost, int endPost) {
  int it = 0;
  while (inOrder[startIn + it] != postOrder[endPost - 1])
    it++;
  printf("%d ", postOrder[endPost - 1]);
  if (it > 0)
    printPre(startIn, startIn + it, startPost, startPost + it);
  if (startIn + it + 1 < endIn)
    printPre(startIn + it + 1, endIn, startPost + it, endPost - 1);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &inOrder[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &postOrder[i]);

  printPre(0, n, 0, n);
  return (0);
}

/*

		a
	b		c
d	 e	  f		g


in: d - b - e - a - f - c - g
post: d - e - b - f - g - c - a
pre: a - b - d - e - c - f - g




