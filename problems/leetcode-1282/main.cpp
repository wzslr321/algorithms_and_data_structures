// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

class Solution {
public:
    vector<vector<int>> groupThePeople(const vector<int> &groupSizes) {

        unordered_map<int, vector<vector<int>>> mp;
        vector<pair<int, vector<int>>> toPush = {};

        vector<vector<int>> ans = {};
        
        unordered_map<int, int> lastOccurence;
        for(size_t i = 0; i < groupSizes.size(); ++i) {
            lastOccurence[groupSizes[i]] = i;
        }
            
        for (int i = 0; i < groupSizes.size(); ++i) {
            auto s = groupSizes[i];
            if (!mp.count(s)) {
                mp[s] = {{i}};
                if (s == 1) {
                    ans.push_back(mp[s][mp[s].size() - 1]);
                }
                continue;
            }

            auto lastGroupI = mp[s].size() - 1;
                if (mp[s][lastGroupI].size() == s) {
                    ans.push_back(mp[s][lastGroupI]);
                    mp[s].push_back({i});
                    continue;
                }

            mp[s][lastGroupI].push_back(i);
            if(mp[s][lastGroupI].size() == s && lastOccurence[s] == i) {
               ans.push_back(mp[s][lastGroupI]);
            }
        }

        return ans;
    }
};