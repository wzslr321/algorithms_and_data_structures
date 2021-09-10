/*
 * Of course I know that this solution is incredibly awful and it doesn't even
 * pass every test cases, but it is my first CP problem I've ever solved
 * so I keep it just to have an insight on how do I progress!
*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mv{};
        map<int,int> mi{};
        vector<int> ni{};
        for (int i{0}; i < nums.size(); i++) {
            int needed{target - nums[i]};
            if (nums[i] == needed){
                ni.push_back(i);
            }
            mv[nums[i]] = needed;
            mi[i] = needed;
            mi[needed] = i; 
            if (nums[i] == mv[needed]) {
                int st = mi[mv[needed]];
                if(st == mi[needed]) {
                    if(ni.size() <= 1) {
                        continue;
                    } else {
                        return vector<int>{ni[0], ni[1]};
                    }
                }
               const vector<int> values = {st, mi[needed]};
                return values;
            }
        }
        const vector<int> values = {};
        return values;
    }
};
