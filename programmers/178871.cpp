// https://school.programmers.co.kr/learn/courses/30/lessons/178871

#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string>
solution(std::vector<std::string> const players,
         std::vector<std::string> const callings) {
  std::vector<std::string> answer(players);
  std::unordered_map<std::string, int> m;

  for (auto it = players.begin(); it != players.end(); ++it) {
    m.insert(make_pair(*it, m.size()));
  }
  for (auto it = callings.begin(); it != callings.end(); ++it) {
    int const index = m[*it];
    --m[*it];
    ++m[answer[index - 1]];
    answer[index] = answer[index - 1];
    answer[index - 1] = *it;
  }
  return answer;
}
