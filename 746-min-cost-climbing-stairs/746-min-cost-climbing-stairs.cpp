class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const auto N = cost.size();
        cost.push_back(0);
        vector<int> best(N + 1);
        best[0] = cost[0], best[1] = cost[1];
        for(size_t i = 0; i < N - 1; ++i) {
           best[i + 2]  = min({best[i] + cost[i + 2],  best[i + 1] + cost[i + 2]});
        }
        return best[N];
    }
};