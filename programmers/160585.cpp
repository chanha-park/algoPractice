#include <string>
#include <vector>

#include <algorithm>

using namespace std;

pair<int, int>
countOX(vector<string> const& board) {
    int countO = 0;
    int countX = 0;

    for (auto const& row : board) {
        for (auto const cell : row) {
            countO += cell == 'O';
            countX += cell == 'X';
        }
    }
    return {countO, countX};
}

pair<int, int>
countWin(vector<string> const& board) {
    constexpr pair<int, int> const startAndSteps[]
        = {{0, 1}, {3, 1}, {6, 1}, {0, 3}, {1, 3}, {2, 3}, {0, 4}, {2, 2}};

    int countOWin = 0;
    int countXWin = 0;

    for (auto const& [start, step] : startAndSteps) {
        auto const c = board[start / 3][start % 3];
        bool exists = true;
        for (int i = 1; i < 3; ++i) {
            if (c != board[(start + step * i) / 3][(start + step * i) % 3]) {
                exists = false;
                break;
            }
        }
        if (exists) {
            countOWin += c == 'O';
            countXWin += c == 'X';
        }
    }
    return {countOWin, countXWin};
}

int
solution(vector<string> board) {
    auto const [countO, countX] = countOX(board);

    if (countO != countX && countO != countX + 1)
        return false;

    auto const [countOWin, countXWin] = countWin(board);

    if (countOWin > 0 && countXWin > 0)
        return false;
    if (countOWin > 0 && countO != countX + 1)
        return false;
    if (countXWin > 0 && countO != countX)
        return false;
    return true;
}
