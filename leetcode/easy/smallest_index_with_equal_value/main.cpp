class Solution {
 public:
  int smallestEqual(vector<int> &nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && i % 10 == 0) j += 10;
      if (nums[i] == i - j) return i;
    }

    return -1;
  }
};
