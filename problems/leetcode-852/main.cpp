// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int worst = 0, best = arr.size() - 2;
        while(worst < best) {
           auto mid = worst + (best - worst)  / 2;
           if(arr[mid] < arr[mid + 1]) worst = mid + 1;
           else best = mid;
        }
        return worst;
    }
};