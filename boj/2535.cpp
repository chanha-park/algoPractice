#include <algorithm>
#include <iostream>
#include <vector>

struct Student {
  int nation, entry, score;

  Student(int nation, int entry, int score) :
      nation(nation), entry(entry), score(score) {
  }

  void
  print(void) const {
    std::cout << nation << " " << entry << std::endl;
  }
};

struct cmp {
  bool
  operator()(const Student& a, const Student& b) {
    return (a.score > b.score);
  }
};

int
main(void) {
  int n, nation, entry, score, t;
  std::cin >> n;
  std::vector<Student> v;
  for (int i = 0; i < n; ++i) {
    std::cin >> nation >> entry >> score;
    v.push_back(Student(nation, entry, score));
  }
  std::sort(v.begin(), v.end(), cmp());
  v[0].print();
  v[1].print();
  t = 2;
  while (v[t].nation == v[0].nation && v[t].nation == v[1].nation)
    ++t;
  v[t].print();
  return (0);
}
