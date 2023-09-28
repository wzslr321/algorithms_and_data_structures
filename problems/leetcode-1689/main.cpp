// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

class Solution {
public:
    int minPartitions(string n) {
       int ans = 0; 
       for(const auto ch : n) {
           ans = max(ch - '0', ans);
       }

       return ans;
    }
};