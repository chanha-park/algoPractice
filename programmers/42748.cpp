
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int>
solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;

  for (auto it = commands.begin(); it != commands.end(); ++it) {
    const vector<int>& command = *it;
    const int i = command[0];
    const int j = command[1];
    const int k = command[2];

    vector<int> slicedVector(&array[i - 1], &array[j]);
    std::sort(slicedVector.begin(), slicedVector.end());
    answer.push_back(slicedVector[k - 1]);
  }
  return answer;
}
