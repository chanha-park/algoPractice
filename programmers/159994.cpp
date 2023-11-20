#include <string>
#include <vector>

using namespace std;

string
solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int index1 = 0;
    int index2 = 0;
    int index = 0;

    while (index < goal.size() && index1 < cards1.size()
           && index2 < cards2.size()) {
        string const& s1 = cards1[index1];
        string const& s2 = cards2[index2];
        string const& s = goal[index];

        if (s == s1) {
            ++index;
            ++index1;
        } else if (s == s2) {
            ++index;
            ++index2;
        } else {
            return "No";
        }
    }
    while (index < goal.size() && index1 < cards1.size()) {
        string const& s1 = cards1[index1];
        string const& s = goal[index];

        if (s == s1) {
            ++index;
            ++index1;
        } else {
            return "No";
        }
    }
    while (index < goal.size() && index2 < cards2.size()) {
        string const& s2 = cards2[index2];
        string const& s = goal[index];

        if (s == s2) {
            ++index;
            ++index2;
        } else {
            return "No";
        }
    }
    return index == goal.size() ? "Yes" : "No";
}
