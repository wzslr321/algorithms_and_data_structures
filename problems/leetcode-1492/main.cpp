// https://leetcode.com/problems/the-kth-factor-of-n/description/

class Solution {
public:
    // Credit for 2nd and 3rd approach:
    // s/708099/c-java-straightforward-sqrt-n/?envType=study-plan-v2&envId=amazon-spring-23-high-f

    // Third approach, O(sqrt(N)) | Credit: 
    int kthFactor(int n, int k) {
        int d = 1;
        for (; d * d <= n; ++d)
            if (n % d == 0 && --k == 0)
                return d;
        for (d = d - 1; d >= 1; --d) {
            if (d * d == n)
                continue;
            if (n % d == 0 && --k == 0)
                return n / d;
        }
        return -1;
    }

    /* Second approach, optimized but still O(N)
    int kthFactor(int n, int k) {
        for (int d = 1; d <= n / 2; ++d)
            if (n % d == 0 && --k == 0)
                return d;
        return k == 1 ? n : -1;
    };
    */

    /* My first approach
    int kthFactor(int n, int k) {
        for(auto i = 1, j = 0; i <= n; i++) {
            if(n % i != 0) {
                continue;
            }
            j++;
            if(j == k) {
                return i;
            }
        }

        return -1;
    }
    */
};