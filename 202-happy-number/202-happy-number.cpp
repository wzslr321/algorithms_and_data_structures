class Solution {
public:
    unordered_map<int, bool> seen;
    bool isHappy(int n) {
        if(seen[n]) return false;
        seen[n] = true;
        auto s = to_string(n);
        auto num = 0;
        for(const auto el : s){
            num += pow((el - 48),2);
        }
        if(num == 1) return true;
        return isHappy(num);
    }
};