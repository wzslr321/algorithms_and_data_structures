class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto curr = s.begin();
        size_t correct = 0;
        for(const auto ch : t) {
            if(ch == *curr) 
                ++curr, ++correct;
            if(correct == s.size()) return true;
        }
        if(correct == s.size()) return true;
        
        return false;  
    }
};