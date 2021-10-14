#include <cassert>
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

using ll = long long;

vector<int> plusOne(vector<int>& digits) {
    bool cf{false};
    int_fast8_t last(digits.size() - 1);

    do {
        if (digits[last] + 1 == 10) {
            cf = true;
            cout << digits[last] << '\t';
            digits[last] = 0;
            cout << digits[last] << '\n';
            --last;
            if (last == -1) {
                digits.insert(digits.begin(), 1);
            }
        } else {
            ++digits[last];
            cf = false;
        }
    } while (cf == true && last >= 0);

    return digits;
}

int main() {
    vector<int> es{8,9,9,9};
    auto res = plusOne(es);
    for (auto i{0}; i < res.size() - 1; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}
