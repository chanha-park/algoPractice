#include <string>
#include <vector>

#include <algorithm>
#include <queue>

using namespace std;

// 오랜만의 bfs. c++17의 structured binding이 편하긴 하다

enum {
    START = 'S',
    EXIT = 'E',
    LEVER = 'L',
    EMPTY = 'O',
    WALL = 'X'
};

int
bfs(vector<string> maps, pair<int, int> const& start, pair<int, int> const& exit
) {
    queue<pair<pair<int, int>, int> > q;

    static int const stepx[] = {1, 0, -1, 0};
    static int const stepy[] = {0, 1, 0, -1};

    int const h = maps.size();
    int const w = maps[0].size();

    maps[start.first][start.second] = WALL;
    q.push({start, 0});

    while (!q.empty()) {
        auto const [top, currentTime] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            pair<int, int> const& next
                = {top.first + stepx[i], top.second + stepy[i]};

            if (next.first < 0 || next.first >= h || next.second < 0
                || next.second >= w) {
                continue;
            }

            if (maps[next.first][next.second] == WALL) {
                continue;
            }

            if (next.first == exit.first && next.second == exit.second) {
                return currentTime + 1;
            }

            maps[next.first][next.second] = WALL;
            q.push({next, currentTime + 1});
        }
    }

    return -1;
}

int
solution(vector<string> maps) {
    pair<int, int> startPos;
    pair<int, int> leverPos;
    pair<int, int> exitPos;

    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[i].size(); ++j) {
            switch (maps[i][j]) {
                case START:
                    startPos = {i, j};
                    break;
                case LEVER:
                    leverPos = {i, j};
                    break;
                case EXIT:
                    exitPos = {i, j};
                    break;
                default:
                    break;
            }
        }
    }

    int const time1 = bfs(maps, startPos, leverPos);

    if (time1 != -1) {
        int const time2 = bfs(maps, leverPos, exitPos);
        if (time2 != -1) {
            return time1 + time2;
        }
    }

    return -1;
}
