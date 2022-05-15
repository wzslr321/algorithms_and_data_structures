class Solution {
public:
vector<int> getRow(int rowIndex) {
    vector<vector<int>> v{{1}, {1, 1}};
    if (rowIndex == 0) return v[0];
    if (rowIndex == 1) return v[1];
    uint row{1};
    while (v.size() <= rowIndex) {
        vector<int> nv{1};
        uint tmp{0};
        for (auto i{1}; i < v[row].size(); i++) {
            nv.push_back(v[row][tmp] + v[row][tmp + 1]);
            ++tmp;
        }
        nv.push_back(1);
        v.push_back(nv);
        row++;
    }

    return v[rowIndex];
}
};