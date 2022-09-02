class Solution {
   public:

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mv{};
    map<int, int> mi1{};
    map<int, int> mi2{};
    vector<int> ni{};
    int l{};
    for (int i{0}; i < nums.size(); i++) {
        l++;
        int needed{target - nums[i]};
        if (nums[i] == needed) {
            ni.push_back(i);
        }
        mv[nums[i]] = needed;
        mi1[i] = needed;
        mi2[needed] = i;
        if (nums[i] == mv[needed]) {
            int st = mi2[mv[needed]];
            if (st == mi2[needed]) {
                if (ni.size() <= 1) {
                    continue;
                } else {
                    return vector<int>{ni[0], ni[1]};
                }
            }
            if (l < 2) continue;
            const vector<int> values = {st, mi2[needed]};
            return values;
        }
    }
    const vector<int> values = {};
    return values;
}


};
