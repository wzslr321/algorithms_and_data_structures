// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       unordered_map<int, int> count;
       vector<int> cp(nums.size());
       int i = 0;
       for(const auto num : nums) {
           if(count[num]) {
               ++count[num];
               if(count[num] > 2) continue;
           } else {
               count[num] = 1;
           }
           cp[i] = num;
           ++i;
       }

       nums = cp;
       return i;
    }
};