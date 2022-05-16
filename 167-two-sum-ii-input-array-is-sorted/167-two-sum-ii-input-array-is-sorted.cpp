class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> needed;
        for(int i = 0; i < numbers.size(); ++i) {
            if(needed[numbers[i]]) {
                vector<int> ans{i + 1, needed[numbers[i]]};
                if(ans[0] > ans[1]) swap(ans[0], ans[1]);
                return ans;
            }
            needed[target - numbers[i]] = i + 1;
        }
        return {};
    }
};