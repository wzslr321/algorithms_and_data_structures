// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid, left = 0, right = n, last_good= 0;
        while(left <= right) {
            mid = left + (right - left)  / 2;
            if(isBadVersion(mid)) {
                if(mid == last_good + 1) return mid;
                right = mid;
            } else {
                last_good = mid;        
                left = mid + 1;
            }
        }
        return 0;
    }
};