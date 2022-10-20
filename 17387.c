#include <stdio.h>

typedef long long ll;

typedef struct {
  ll x;
  ll y;
} point;

ll det(point p1, point p2) {
  return (p1.x * p2.y - p1.y * p2.x);
}

void printPoint(point p) {
  printf("(%lld, %lld)\n", p.x, p.y);
}

int isBetween(point p, point a, point b) {
  if (a.x == b.x) {
    if (a.y == b.y) {
      return ((p.x == a.x) && (p.y == a.y));
    }
    return ((a.y <= p.y && p.y <= b.y) || (b.y <= p.y && p.y <= a.y));
  }
  return ((a.x <= p.x && p.x <= b.x) || (b.x <= p.x && p.x <= a.x));
}

point vec(point p1, point p2) {
  point ans = {p2.x - p1.x, p2.y - p1.y};

  return (ans);
}

int check(point p1, point p2, point p3, point p4) {
  point u = vec(p1, p3);
  point v = vec(p1, p4);
  point w = vec(p1, p2);

  ll d = det(u, v);

  if (d == 0) {
    if (isBetween(p1, p3, p4))
      return (1);
    u = vec(p2, p3);
    v = vec(p2, p4);
    d = det(u, v);
    if (d != 0)
      return (0);
    return (isBetween(p3, p1, p2) || isBetween(p4, p1, p2));
  }

  double a = (double)det(w, v) / d;
  double b = (double)det(u, w) / d;

  return (a >= 0 && b >= 0 && (a + b >= 1));
}

int main(void) {
  point p1, p2, p3, p4;

  scanf("%lld %lld %lld %lld", &p1.x, &p1.y, &p2.x, &p2.y);
  scanf("%lld %lld %lld %lld", &p3.x, &p3.y, &p4.x, &p4.y);

  printf("%d\n", check(p1, p2, p3, p4));

  return (0);
}
