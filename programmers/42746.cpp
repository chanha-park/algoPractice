#include <algorithm>
#include <string>
#include <vector>

bool
cmp(const std::string& a, const std::string& b) {
  return (b + a).compare(a + b) < 0;
}

std::string
solution(std::vector<int> numbers) {
  std::vector<std::string> stringVector;

  for (auto n : numbers) {
    stringVector.push_back(std::to_string(n));
  }

  sort(stringVector.begin(), stringVector.end(), cmp);

  if (stringVector[0] == "0") {
    return "0";
  }

  std::string answer = "";

  for (auto str : stringVector) {
    answer += str;
  }

  return answer;
}
