class Solution {
public:
    string reverseWords(string s) {
        const int N = s.size();
        for(size_t i = 0; i < N; ++i) {
            size_t j = i;
            while(j < N && s[j] != ' ') {
                ++j;
            }
            for(size_t w = 0; w < (j - i) / 2; ++w){
                swap(s[i + w], s[j - w - 1]);
            }
            i = j; 
        }
        return s;
    }
};