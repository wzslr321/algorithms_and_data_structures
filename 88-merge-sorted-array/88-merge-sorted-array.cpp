class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res{};
        int i = 0, j = 0;
        for(int it = 0; it < n + m; ++it) {
           if(i >= m){
               res.push_back(nums2[j]);
               ++j;
               continue;
           }
           if(j >= n) {
               res.push_back(nums1[i]);
               ++i;
               continue;
           }
           if(nums1[i] < nums2[j]) {
               res.push_back(nums1[i]);
               ++i;
           } else {
               res.push_back(nums2[j]);
               ++j;
           }
        }
        
        for(int i = 0; i < n + m; ++i) {
            nums1[i] = res[i];
        }
    }
};