class Solution {
public:
    void reverseString(vector<char>& s) {
        const auto N = s.size();
        for(size_t i = 0; i < N / 2; ++i){
            swap(s[i], s[N - i - 1]);
        }
    }
};