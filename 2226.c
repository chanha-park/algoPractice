#include <stdio.h>
#include <stdlib.h>

typedef struct strInt {
  char* num;
  int size;
  int len;
} strInt;

strInt initStrInt(int nbr) {
  strInt n;

  if (nbr == 0) {
    n.size = 2;
    n.len = 1;
    n.num = malloc(sizeof(char) * n.size);
    n.num[0] = '0';
    n.num[1] = '\0';
  } else {
    n.size = 11;
    n.len = 0;
    n.num = malloc(sizeof(char) * n.size);
    while (nbr) {
      n.num[n.len++] = nbr % 10 + '0';
      nbr /= 10;
    }
    n.num[n.len] = '\0';
  }
  return (n);
}

void deleteStrInt(strInt* n) {
  free(n->num);
  n->num = NULL;
  n->len = 0;
  n->size = 0;
}

strInt addStrInt(strInt a, strInt b) {
  strInt c;
  int temp;
  int carr = 0;
  int len = 0;

  c.size = a.size > b.size ? a.size : b.size;
  c.size++;
  c.num = malloc(sizeof(char) * c.size);
  while (len < a.len && len < b.len) {
    temp = a.num[len] + b.num[len] - 96 + carr;
    c.num[len++] = temp % 10 + '0';
    carr = temp / 10;
  }
  if (len == a.len) {
    while (len < b.len) {
      temp = b.num[len] - 48 + carr;
      c.num[len++] = temp % 10 + '0';
      carr = temp / 10;
    }
  } else if (len == b.len) {
    while (len < a.len) {
      temp = a.num[len] - 48 + carr;
      c.num[len++] = temp % 10 + '0';
      carr = temp / 10;
    }
  }
  if (carr)
    c.num[len++] = carr + '0';
  c.num[len] = '\0';
  c.len = len;
  return (c);
}

void printStrInt(strInt n) {
  for (int i = n.len - 1; i >= 0; i--) {
    printf("%c", n.num[i]);
  }
  printf("\n");
}

int main(void) {
  int n;
  strInt a, b, c;

  scanf("%d", &n);
  a = initStrInt(0);
  for (int i = 1; i < n; i++) {
    b = addStrInt(a, a);
    deleteStrInt(&a);
    if (i % 2) {
      a = initStrInt(1);
      c = addStrInt(b, a);
      deleteStrInt(&a);
      deleteStrInt(&b);
      a = c;
    } else {
      b.num[0] -= 1;
      a = b;
    }
  }
  printStrInt(a);
  deleteStrInt(&a);
  return (0);
}
