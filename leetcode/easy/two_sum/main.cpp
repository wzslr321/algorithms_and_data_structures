
/*
 *
 * https://leetcode.com/problems/two-sum/
 *
 * Of course I know that this solution is incredibly awful,
 * but it is my first CP problem I've ever solved
 * so I keep it just to have an insight on how do I progress!
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mv{};
    map<int, int> mi1{};
    map<int, int> mi2{};
    vector<int> ni{};
    int l{};
    for (int i{0}; i < nums.size(); i++) {
        l++;
        int needed{target - nums[i]};
        if (nums[i] == needed) {
            ni.push_back(i);
        }
        mv[nums[i]] = needed;
        mi1[i] = needed;
        mi2[needed] = i;
        if (nums[i] == mv[needed]) {
            int st = mi2[mv[needed]];
            if (st == mi2[needed]) {
                if (ni.size() <= 1) {
                    continue;
                } else {
                    return vector<int>{ni[0], ni[1]};
                }
            }
            if (l < 2) continue;
            const vector<int> values = {st, mi2[needed]};
            return values;
        }
    }
    const vector<int> values = {};
    return values;
}

int main() {
    vector<int> arr{-6, 1, 0, 4};
    int target{-5};
    auto values{twoSum(arr, target)};

    for (int value : values) {
        cout << value << '\n';
    }

    return 0;
}

