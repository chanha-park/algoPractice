#include <cstring>
#include <iostream>
#include <string>

#define MOD 10000

int op_d(int n) {
  return ((2 * n) % MOD);
}

int op_s(int n) {
  return ((n + MOD - 1) % MOD);
}

int op_l(int n) {
  n *= 10;
  return ((n + (n / MOD)) % MOD);
}

int op_r(int n) {
  int tmp = n % 10;

  return ((n / 10) + (tmp * MOD / 10));
}

namespace myBOJ {

char visited[MOD];

class List {
 public:
  List* next;
  int data;
  std::string cmd;

  List(void) : next(NULL), data(0), cmd("") {
  }

  List(int data) : next(NULL), data(data), cmd("") {
  }

  List(const List& other) : next(other.next), data(other.data), cmd(other.cmd) {
  }

  const List& operator=(const List& other) {
    if (this != &other) {
      next = other.next;
      data = other.data;
      cmd = other.cmd;
    }
    return (*this);
  }

  ~List(void) {
  }

  List(const List& other, std::string c) {
    this->next = NULL;
    this->cmd = other.cmd + c;
    switch (c[0]) {
      case ('D'):
        data = op_d(other.data);
        break;
      case ('S'):
        data = op_s(other.data);
        break;
      case ('L'):
        data = op_l(other.data);
        break;
      case ('R'):
        data = op_r(other.data);
        break;
      default:
        data = 0;
        break;
    }
  }
};

class Que {
 public:
  List* head;
  List* tail;

  Que(void) : head(NULL), tail(NULL) {
  }

  ~Que(void) {
    while (!isEmpty())
      delete (deQue());
    head = NULL;
    tail = NULL;
  }

  void enQue(List newNode) {
    if (myBOJ::visited[newNode.data] == 1)
      return;
    List* tmp = new List(newNode);
    if (head)
      tail->next = tmp;
    else
      head = tmp;
    tail = tmp;
    myBOJ::visited[newNode.data] = 1;
  }

  List* deQue(void) {
    List* tmp = head;

    head = head->next;
    if (!head)
      tail = NULL;
    return (tmp);
  }

  int isEmpty(void) {
    return (head == NULL);
  }
};

}  // namespace myBOJ

void testcase(void) {
  int a, b;

  std::cin >> a >> b;

  memset(myBOJ::visited, 0, MOD);

  myBOJ::Que que;
  myBOJ::List* tmp;

  que.enQue(myBOJ::List(a));
  if (que.tail->data == b) {
    std::cout << que.tail->cmd << std::endl;
    return;
  }
  while (!que.isEmpty()) {
    tmp = que.deQue();
    que.enQue(myBOJ::List(*tmp, "D"));
    if (que.head && que.tail->data == b) {
      std::cout << que.tail->cmd << std::endl;
      delete tmp;
      return;
    }
    que.enQue(myBOJ::List(*tmp, "S"));
    if (que.head && que.tail->data == b) {
      std::cout << que.tail->cmd << std::endl;
      delete tmp;
      return;
    }
    que.enQue(myBOJ::List(*tmp, "L"));
    if (que.head && que.tail->data == b) {
      std::cout << que.tail->cmd << std::endl;
      delete tmp;
      return;
    }
    que.enQue(myBOJ::List(*tmp, "R"));
    if (que.head && que.tail->data == b) {
      std::cout << que.tail->cmd << std::endl;
      delete tmp;
      return;
    }
    delete tmp;
  }
}

int main(void) {
  int t;

  std::cin >> t;
  for (int i = 0; i < t; i++)
    testcase();
  return (0);
}
