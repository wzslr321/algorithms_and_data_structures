class Solution {
public:
    int minOperations(vector<int>& nums) {
        auto count{0};
        for(auto i{1}; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                auto dif{nums[i-1] - nums[i] + 1};
                count += dif;
                nums[i] += dif;
            } 
        }
        return count;
    }
};