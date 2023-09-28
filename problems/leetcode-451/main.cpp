// https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
private:
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(const auto c: s)
            freq[c] ? ++freq[c] : freq[c] = 1;

        vector<pair<char,int>> freqVec;
        for(const auto& p : freq)
            freqVec.emplace_back(p);

        sort(freqVec.begin(), freqVec.end(), [](const auto& p1, const auto &p2){
          return p1.second > p2.second;
        });

        string ans = "";
        ans.resize(s.size());
        int i = 0;
        for(const auto& p : freqVec) {
            for(int j = 0; j < p.second; ++j) {
                ans[i + j] = p.first;
            }
            i += p.second;
        }

        return ans;
    }
};