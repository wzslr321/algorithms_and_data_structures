class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans {};
        int zeros_count = 0;
        for(const auto el: nums) {
            if(el != 0) ans.push_back(el);
            else ++zeros_count;
        }
        
        for(int i = 0; i < zeros_count; ++i) 
            ans.push_back(0);
        
        for(size_t i = 0; i < nums.size(); ++i)
            nums[i] = ans[i];
    }
};