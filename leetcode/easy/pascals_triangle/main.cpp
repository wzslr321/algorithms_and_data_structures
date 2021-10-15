#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v1{{1}};
    vector<vector<int>> v{{1}, {1, 1}};  // 1 2 1
    if (numRows == 1) return v1;
    if (numRows == 2) return v;
    while (v.size() < numRows) {
        vector<int> nv{1};
        uint tmp{0};
        for (auto i{1}; i < v.size(); i++) {
            cout << tmp << '\n';
            nv.push_back(v[i][tmp] + v[i][tmp + 1]);
            cout << "Hello" << '\n';
            ++tmp;
        }
        nv.push_back(1);
        v.push_back(nv);
    }

    /*
    for (auto i{0}; i < v.size(); i++) {
        for (auto j{0}; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    */

    return v;
}

int main() {
    generate(3);
    cout << "=========" << '\n';
    generate(4);
    cout << "=========" << '\n';
    generate(5);

    return 0;
}
