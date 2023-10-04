// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = count(nums.begin(), nums.end(), 1);
        int n = nums.size(), ans = n;

        for(int i = 0, j = 0, cnt = 0; i < n; ++i) {
            // expands window on first iteration
            // then it just slides it as i increases 
            while(j - i < ones)
                cnt += nums[j++ % n]; // j++ % n, because list is circular
            ans = min(ans, ones - cnt);
            cnt -= nums[i];
        }

        return ans;
    }
};
