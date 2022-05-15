class Solution {
public:
    string generateTheString(int n) {
        return n % 2 == 0 ? string(n - 1, 'a') + 'b' : string(n, 'a');
    }        
};