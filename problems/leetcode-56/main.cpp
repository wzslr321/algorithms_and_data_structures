// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (const auto interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
                continue;
            }

            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
        return ans;
    }
};