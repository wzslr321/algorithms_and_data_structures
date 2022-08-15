class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
       const int N = nums.size();
       vector<int> sums(N);
       auto current_sum = 0, index = -1;
       for(const auto num : nums) {
           current_sum += num, ++index;
           sums[index] = current_sum;
       }
        
       return sums;
    }
};