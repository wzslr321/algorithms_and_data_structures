#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {}

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val{2};
    vector<int> expectedNums = {0, 1, 4, 0, 3};

    int k{removeElement(nums, val)};

    assert(k == expectedNums.size());
    sort(nums, 0, k);
    for (auto i{0}; i < actualLength; i++) {
        assert(nums[i] == expectedNums[i]);
    }

    return 0;
}

