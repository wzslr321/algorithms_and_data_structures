// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> opening;

        int ans = 0;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ')') {
                if(!opening.empty()) {
                    opening.pop();
                    continue;
                }
                ++ans;
            } else {
                opening.push(s[i]);
            }
        }

        return ans + opening.size();
    }
};