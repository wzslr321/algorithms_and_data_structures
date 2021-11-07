#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    int mx = 0;
    vector<vector<int>> all;
    vector<int> maxo;
    for (auto j{0}; j < t; ++j) {
        int n;
        cin >> n;
        int mxo = 0;
        vector<int> arr(n);
        for (auto i{0}; i < n; ++i) {
            int val;
            cin >> val;
            mx = max(mx, val);
            mxo = max(mxo, val);
            arr[i] = val;
        }
        all.push_back(arr);
        maxo.push_back(mxo);
    }

    int sum = 0;
    for (auto i{0}; i < all.size(); ++i) {
        int diff = mx - maxo[i];
        for (auto j{0}; j < all[i].size(); ++j) {
            all[i][j] += diff;
            sum += diff;
        }
    }

    cout << sum << '\n';

    return 0;
}
