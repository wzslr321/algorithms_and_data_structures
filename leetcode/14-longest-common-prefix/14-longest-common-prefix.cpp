class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
    if (strs[0] == "") {
        return "";
    }

    string prefix{strs[0]};

    for (int i{}; i < strs.size(); i++) {
        if (strs[i] == "") {
            return "";
        }
        for (int j{}; j < strs[i].size(); j++) {
        
            if ((j == 0) && strs[i][j] != prefix[j]) {
                return "";
            }

            if (strs[i].size() < prefix.size()) {
                prefix = prefix.substr(0, strs[i].size());
            }

            if (strs[i][j] != prefix[j]) {
                prefix = prefix.substr(0, j);
            }
        }
    }

    return prefix;
}
};
    
    