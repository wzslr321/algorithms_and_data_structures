class Solution {
public:
    unordered_map<int, bool> seen;
    bool isHappy(int n) {
        if(seen[n]) return false;
        seen[n] = true;
        auto num = 0;
        while(n > 0) {
            auto d = n % 10;
            n /= 10;
            num += d * d;
        }
        if(num == 1) return true;
        return isHappy(num);
    }
};