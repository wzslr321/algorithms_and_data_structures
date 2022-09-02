class Solution {
public:
int maxSubArray(vector<int>& nums) {
    int best{1<<31}, sum{0};
    for (auto i{0}; i < nums.size(); i++) {
        sum = max(nums[i], sum + nums[i]);
        best = max(best, sum);
    }
    return best;
}
};