class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int MAX = 1007;
        vector<int> seen(MAX);
        fill(seen.begin(), seen.end(), 0);
        vector<int> added(MAX);
        fill(added.begin(), added.end(), 0);
        for(const auto el: nums1)    
            ++seen[el];
        vector<int> ans{};
        for(const auto el: nums2)  {
           if(seen[el] > added[el]) {
               ++added[el];
               ans.push_back(el);
           }
        }
        return ans;
    }
};