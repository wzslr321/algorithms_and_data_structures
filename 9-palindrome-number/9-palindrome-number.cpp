class Solution {
public:
   bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    } else if (x < 10) {
        return true;
    }

    long long rv{};
    int xdef{x};

    while (x > 0) {
        rv *= 10;
        rv += (x % 10);
        x /= 10;
    }

    if (rv == xdef) {
        return true;
    }

    return false;
}
};