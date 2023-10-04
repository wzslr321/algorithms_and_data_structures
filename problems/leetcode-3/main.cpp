// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
     int lengthOfLongestSubstring(const std::string s) {
         int n = s.size();
         unordered_map<char, int> seen;
         int ans = 0.;
         for(int i = 0, j = 0; j < n; j++) {
             if(seen[s[j]]) {
                 i = max(i, seen[s[j]]);
             }
             ans = max(ans, j - i + 1);
             seen[s[j]] = j + 1;
         }
         return ans;
     }
};
