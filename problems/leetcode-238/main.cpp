// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto N = nums.size();
        vector<int>ans(N), left(N), right(N);
            
        for(int i = 0, vali = 1, valj = 1, j = N - 1; i < N; ++i, --j) 
            vali *= nums[i], valj *= nums[j], left[i] = vali, right[j] = valj;
        
        ans[0] = right[1], ans[N - 1] = left[N - 2];
        for(size_t i = 1; i < N - 1; ++i) 
            ans[i] = right[i + 1] * left[i - 1];
        
        return ans;
    }
};