#include <stdio.h>

#define SIZE 100001

typedef struct {
  int pos;
  int time;
} pair;

int visit[SIZE];
pair queue[SIZE];
int head, tail;

int isVisit(int a) {
  return (visit[a]);
}

void markVisit(int a, int b) {
  visit[a] = b;
}

void enque(int a, int t) {
  queue[tail++] = (pair){a, t};
  tail %= SIZE;
}

pair deque(void) {
  pair tmp = queue[head++];
  head %= SIZE;
  return (tmp);
}

int isEmpty(void) {
  return (head == tail);
}

int goFront(int a) {
  return (a + 1);
}

int goBack(int a) {
  return (a - 1);
}

int goDouble(int a) {
  return (a << 1);
}

static int (*func[3])(int) = {goFront, goBack, goDouble};

int main(void) {
  int n, k, minTime, countAns;
  scanf("%d %d", &n, &k);
  if (n >= k) {
    printf("%d\n1\n", n - k);
    return (0);
  }
  minTime = SIZE;
  countAns = 0;
  markVisit(n, 0);
  enque(n, 0);
  while (!isEmpty()) {
    pair tmp = deque();
    if (tmp.time >= minTime)
      break;
    for (int i = 0; i < 3; ++i) {
      int nextPos = func[i](tmp.pos);
      if (nextPos == k) {
        minTime = tmp.time + 1;
        countAns++;
        continue;
      }
      if (nextPos < 0 || nextPos >= SIZE)
        continue;
      if (isVisit(nextPos) && visit[nextPos] < tmp.time + 1)
        continue;
      markVisit(nextPos, tmp.time + 1);
      enque(nextPos, tmp.time + 1);
    }
  }
  printf("%d\n%d\n", minTime, countAns);
  return (0);
}
