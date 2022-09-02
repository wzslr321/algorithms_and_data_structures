class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int MAX = 1007;
        
        vector<int> seen(MAX);
        vector<int> added(MAX);
        vector<int> ans{};
        
        for(const auto el: nums1)    
            ++seen[el];
        for(const auto el: nums2)  
           if(seen[el] > added[el]) ++added[el], ans.push_back(el);
        
        return ans;
    }
};