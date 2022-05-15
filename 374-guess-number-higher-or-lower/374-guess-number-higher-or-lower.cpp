/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int mid, left = 0, right = n;
        auto res = 1;
        while(res != 0) {
           mid = left + (right - left) / 2;
           res = guess(mid);
           if(res == -1) right = mid - 1;
           if(res == 1)  left = mid + 1;
        }
        return mid;
    }
};