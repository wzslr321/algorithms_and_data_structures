class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0; i < 31; ++i) {
           if(n == 1 << i || i == 1 >> i)  return true;
        }
        
        return false;
    }
};