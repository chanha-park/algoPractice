#include <string>
#include <vector>

#include <algorithm>
#include <iostream>

using namespace std;

// two pointer, O(n)
vector<int>
solution(vector<int> sequence, int const k) {
    int left_save = sequence.size();
    int right_save = left_save;
    int sum = sequence[0];

    for (int left = 0, right = 0; left <= right && right < sequence.size();) {
        if (sum < k) {
            if (right + 1 < sequence.size()) {
                sum += sequence[++right];
            } else {
                break;
            }
        } else {
            if (sum == k
                && (left_save == sequence.size()
                    || right - left < right_save - left_save)) {
                left_save = left;
                right_save = right;
            }
            sum -= sequence[left++];
        }
    }

    return vector<int>{left_save, right_save};
}

// 누적합 이용한 풀이 -> O(n + nlogn)
// #include <string>
// #include <vector>
//
// #include <algorithm>
// #include <iostream>
//
// using namespace std;
//
// vector<int>
// solution(vector<int> sequence, int k) {
//     vector<int> accum;
//     accum.reserve(sequence.size() + 1);
//
//     accum.push_back(0);
//     for (int i = 0; i < sequence.size(); ++i) {
//         accum.push_back(accum[i] + sequence[i]);
//     }
//
//     int left_save = accum.size();
//     int right_save = left_save;
//
//     for (int left = 0; left < accum.size(); ++left) {
//         auto it
//             = lower_bound(accum.begin() + left, accum.end(), k +
//             accum[left]);
//         int const right = it - accum.begin();
//
//         if (right < accum.size() && accum[right] - accum[left] == k) {
//             if (left_save == accum.size()
//                 || right - left < right_save - left_save) {
//                 left_save = left;
//                 right_save = right;
//             }
//         }
//     }
//
//     return vector<int>{left_save, right_save - 1};
// }
