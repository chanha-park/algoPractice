#include <stdio.h>

int cow[26][3];

int	meet(int a, int b, int c, int d)
{
	int	x = (a < c) && (c < b);
	int	y = (a < d) && (d < b);

	return (x ^ y);
}

int main(void) {
  char input[53];
  scanf("%s", input);

  for (int i = 0; input[i]; i++) {
    if (cow[input[i] - 'A'][0]) {
      cow[input[i] - 'A'][2] = i;
    } else {
      cow[input[i] - 'A'][0] = 1;
      cow[input[i] - 'A'][1] = i;
    }
  }

  int count = 0;

  for (int i = 0; i < 26; i++) {
    for (int j = i + 1; j < 26; j++) {
      count += meet(cow[i][1], cow[i][2], cow[j][1], cow[j][2]);
    }
  }

  printf("%d\n", count);
  return (0);
}
