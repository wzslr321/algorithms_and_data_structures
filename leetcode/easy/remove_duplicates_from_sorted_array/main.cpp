#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    auto size{nums.size()};

    if (size < 1) {
        return 0;
    }
    auto rm{0};

    for (auto i{0}; i < (nums.size() - 1); i++) {
        if (nums[i] == nums[i + 1]) {
            ++rm;
            nums.erase(nums.begin() + i);
            --i;
        }
    }

    cout << rm << '\n';

    return (size - rm);
}

int main() {
    vector<int> nums = {};
    vector<int> expectedNums = {};

    int k = removeDuplicates(nums);

    cout << k << '\n';
    cout << expectedNums.size() << '\n';
    assert(k == expectedNums.size());
    for (auto i{0}; i < k; i++) {
        cout << nums[i] << '\t' << expectedNums[i] << '\n';
        assert(nums[i] == expectedNums[i]);
    }

    return 0;
}
