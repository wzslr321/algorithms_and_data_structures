class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        size_t NO = grid.size(), N = grid[0].size();
        
        vector<vector<int>> ans(NO, vector<int>(N));
        
        k %= NO * N;
        
        for(size_t i = 0; i < NO; ++i) {
            for(size_t j = 0; j < N; ++j) {
                size_t r = (j + k) / N;
                ans[i + r - ((i + r) / NO) * NO][j + k - (N * r)] = grid[i][j];
            }
        }
        
        return ans;
    }
};