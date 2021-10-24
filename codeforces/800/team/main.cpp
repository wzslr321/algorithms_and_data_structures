#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double

int main() {
    auto n{0};
    cin >> n;
    auto b{0};
    for (auto i{0}; i < n; ++i) {
        auto a{0};
        for (auto j{0}; j < 3; ++j) {
            auto x{0};
            cin >> x;
            if (x == 1) {
                ++a;
            }
        }
        if (a > 1) ++b;
    }

    cout << b;

    return 0;
}
