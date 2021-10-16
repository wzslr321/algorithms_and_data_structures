#include <cassert>
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

using ll = long long;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> v{{1}, {1, 1}};
    if (rowIndex == 0) return v[0];
    if (rowIndex == 1) return v[1];
    uint_fast8_t row{1};
    while (v.size() <= rowIndex) {
        vector<int> nv{1};
        uint_fast8_t tmp{0};
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

int main() {
    auto v = getRow(3);
    for (auto i{0}; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
