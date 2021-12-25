#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int> &nums) {
  auto count{0};
  for (auto i{1}; i < nums.size(); i++) {
    if (nums[i] <= nums[i - 1]) {
      auto dif{nums[i - 1] - nums[i] + 1};
      count += dif;
      nums[i] += dif;
    };
  }
  return count;
}

int main() {
  vector<int> nums{1, 5, 2, 4, 1};
  cout << minOperations(nums);

  return 0;
}
