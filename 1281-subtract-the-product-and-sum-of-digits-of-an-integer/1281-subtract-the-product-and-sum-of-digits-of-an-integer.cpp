class Solution {
public:
    int subtractProductAndSum(int n) {
        int mod = 10, prod = 1, sum = 0;
        while(mod <= n * 10) {
           int digit = n % mod;
           n -= digit;
           digit /= (mod / 10);
           prod *= digit;
           sum += digit; 
           mod *= 10;
        }
        return prod - sum;
    }
};