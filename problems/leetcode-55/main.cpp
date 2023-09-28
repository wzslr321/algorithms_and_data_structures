// https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0, reach = 0; i < nums.size(); ++i) {
            if(reach < i) return false;
            reach = max(i + nums[i], reach);
        }

        return true;
    }
};