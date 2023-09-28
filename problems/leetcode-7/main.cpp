// https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
    int low_int{(1 << 31)};
    int max_int{(low_int + 1) * (-1)};

    if (x <= low_int || x >= max_int) return 0;

    long long rv_int{0};
    int l{10};
    int lp{0};
    if (x > 0) {
        while (x > 0) {
            if (lp == 0) {
                rv_int += (x % 10);
                x /= 10;
                lp++;

            } else {
                if ((rv_int * l) > max_int ) {
                    return 0;
                }
                rv_int *= l;
                rv_int += (x % 10);
                x /= 10;
            }
        }
    }

    if (x < 0) {
        while (x < 0) {
            if (lp == 0) {
                rv_int += (x % 10);
                x /= 10;
                lp++;
            } else {
                if ((rv_int * l) < low_int) {
                    return 0;
                }
                rv_int *= l;
                rv_int += (x % 10);
                x /= 10;
            }
        }
    }

    return rv_int;
}
};