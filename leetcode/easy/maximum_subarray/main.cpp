#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int maxSubArray(vector<int> &nums) {
  int low_int{(1 << 31)};
  auto best{low_int}, sum{0};
  for (auto i{0}; i < nums.size(); i++) {
    sum = max(nums[i], sum + nums[i]);
    best = max(best, sum);
  }
  return best;
}

int main() {
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

  assert((maxSubArray(nums), 6));

  return 0;
}
