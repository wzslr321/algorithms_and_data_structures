class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for(const auto el : nums) {
            if(!count) candidate = el;
            el == candidate ? ++count : --count;
        }
        return candidate;
    }
};