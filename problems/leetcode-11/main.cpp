// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while(i < j) {
            if(height[i] < height[j]) {
                ans = max(ans, (j - i) * height[i]);
                ++i;
                continue;
            }
            ans = max(ans, (j - i) * height[j]);
            --j;
        }
        return ans;
    }
};