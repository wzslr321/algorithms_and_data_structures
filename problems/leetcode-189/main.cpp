// https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto const N = nums.size();
        
        vector<int> ans(N);
        
        for(size_t i = 0; i < N; ++i) {
           auto j = i + k;
           while(j >= N) {
               j -= N;
           }
           ans[j] = nums[i];
        }
        
        for(size_t i = 0; i < N; ++i) {
            nums[i] = ans[i];
        }
    }
};