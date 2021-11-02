#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    vector<vector<int>> nvd{};
    int h{0};
    vector<int> nv{};
    for (auto i{0}; i < mat.size(); i++) {
        for (auto j{0}; j < mat[i].size(); j++) {
            if (nv.size() < c && h < c / r) {
                nv.push_back(mat[i][j]);
                h++;
            } else {
                nvd.push_back(nv);
                nv.clear();
                nv.push_back(mat[i][j]);
                h = 0;
            }
        }
    }

    if (nvd.size() < r) {
        nvd.push_back(nv);
    }

    for (auto i{0}; i < nvd.size(); i++) {
        for (auto j{0}; j < nvd[i].size(); j++) {
            cout << nvd[i][j] << " ";
        }
        cout << '\n';
    }

    return nvd;
}

int main() {
    vector<vector<int>> mat = {{1, 2}, {3, 4}};  // [[1,2,3,4]]
    int r{1}, c{4};

    vector<vector<int>> mat2 = {{1, 2}, {3, 4}};  // [[1,2],[3,4]]
    int r2{2}, c2{4};

    matrixReshape(mat, r, c);
    matrixReshape(mat2, r2, c2);

    return 0;
}
