class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        auto diff = arr[1] - arr[0];
        for(size_t i = 0 ; i < arr.size() - 1; ++i)
            if(arr[i + 1] - arr[i] != diff) return false;
        return true;
    }
};