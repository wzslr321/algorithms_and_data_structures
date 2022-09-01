class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(2060, 0);
        auto max = 0, ans = INT_MAX;
        for(const auto& log: logs){
            for(int j = log[0]; j < log[1]; ++j) {
               ++years[j];
               if(years[j] > max){
                   max = years[j];
                   ans = j;
               }
               if(years[j] == max) {
                   if(j < ans) ans = j;
               }
            }
        }
        
        return ans;     
    }
};