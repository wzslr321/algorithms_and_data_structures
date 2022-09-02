class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(size_t i = 0; i < s.size(); ++i){
            unordered_map<char,bool> seen;
            int count = 0;
            int j = i;
            while(j < s.size() && !seen[s[j]]) {
               ++count, seen[s[j]] = true, ++j;
            }
            ans = max(ans, count);
        }
        
        return ans;
    }
};