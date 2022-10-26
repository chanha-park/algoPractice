#include <stdio.h>

int n;
int map[100000][3];
int min[3];
int max[3];

void updateMin(const int curr) {
  const int a = min[0];
  const int b = min[1];
  const int c = min[2];
  int x, y;

  x = (a < b ? a : b);
  min[0] = map[curr][0] + x;

  y = (b < c ? b : c);
  min[2] = map[curr][2] + y;

  min[1] = map[curr][1] + (x < y ? x : y);
}

void updateMax(int curr) {
  const int a = max[0];
  const int b = max[1];
  const int c = max[2];
  int x, y;

  x = (a > b ? a : b);
  max[0] = map[curr][0] + x;

  y = (b > c ? b : c);
  max[2] = map[curr][2] + y;

  max[1] = map[curr][1] + (x > y ? x : y);
}

int min3(void) {
  int ret = min[0];

  if (ret > min[1])
    ret = min[1];
  if (ret > min[2])
    ret = min[2];

  return (ret);
}

int max3(void) {
  int ret = max[0];

  if (ret < max[1])
    ret = max[1];
  if (ret < max[2])
    ret = max[2];

  return (ret);
}

int main(void) {
  scanf("%d", &n);
  scanf("%d %d %d", &map[0][0], &map[0][1], &map[0][2]);
  min[0] = max[0] = map[0][0];
  min[1] = max[1] = map[0][1];
  min[2] = max[2] = map[0][2];
  for (int i = 1; i < n; ++i) {
    scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
    updateMin(i);
    updateMax(i);
  }
  printf("%d %d\n", max3(), min3());
  return (0);
}
