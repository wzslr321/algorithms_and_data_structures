#define PB push_back 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int best = INT_MAX;    
        auto N = nums.size();
        int best_i;
        for(size_t i = 0; i < N; ++i) {
            if(nums[i] < 0) nums[i] *= -1;
            if(nums[i] < best) best = nums[i], best_i = i;
        }
        
        int left = best_i - 1, right = best_i + 1;
        vector<int> ans{};
        ans.PB(pow(nums[best_i],2));
        while(ans.size() != N) {
           if(left < 0) {
              ans.PB(pow(nums[right],2)), ++right;
              continue;
           }
           if(right >= nums.size()) {
              ans.PB(pow(nums[left], 2)), --left;
              continue;
           }
           if(nums[left] < nums[right]) ans.PB(pow(nums[left],2)), --left;
           else ans.PB(pow(nums[right],2)), ++right;
        }
        
        return ans;
    }
    
};