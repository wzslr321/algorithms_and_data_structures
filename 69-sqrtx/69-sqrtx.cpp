class Solution {
public:
  int mySqrt(int x) {
    long long n{0};
    while (x > n * n) {
        n++;
    }

    if (n * n > x) return n - 1;
    return n;
};
};