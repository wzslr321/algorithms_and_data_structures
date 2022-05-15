class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto dp {0};
        
        for(auto i{0}; i < nums.size(); i++){
            if (nums[i] != val) {
                nums[dp] = nums[i];
                dp++;
            }
        }
        
        return dp;
    }
};