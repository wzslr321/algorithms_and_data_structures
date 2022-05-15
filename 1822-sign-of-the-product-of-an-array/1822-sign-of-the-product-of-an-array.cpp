class Solution {
public:
    int arraySign(vector<int>& nums) {
        uint s{1};
        for(auto i{0}; i < nums.size(); i++){
            if(nums[i] == 0) return 0;
            if(nums[i] < 0) {
               s == 1 ? s = -1 : s = 1;
            }
        }
            
        return s;
    }
};