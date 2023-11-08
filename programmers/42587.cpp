#include <queue>
#include <string>
#include <vector>

using namespace std;

int
solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int> pq(priorities.begin(), priorities.end());
    queue<int> q;
    for (auto const& k : priorities) {
        q.push(k);
    }

    while (!q.empty()) {
        int const front = q.front();
        q.pop();
        if (front == pq.top()) {
            pq.pop();
            ++answer;
            if (location == 0)
                break;
        } else {
            q.push(front);
        }
        location = location == 0 ? q.size() - 1 : location - 1;
    }
    return answer;
}
