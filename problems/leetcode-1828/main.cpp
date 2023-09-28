// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/description/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        size_t N = queries.size();
        vector<int> ans(N);
        for(size_t i = 0; i < N; ++i) {
            auto xa = queries[i][0], ya = queries[i][1], r = queries[i][2];
            int qans = 0;
            for(const auto point: points) {
                auto  xb = point[0], yb = point[1];
                auto d = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
                if(d <= r) ++qans;
            }
            ans[i] = qans;
        }
        
        return ans;
    }
};