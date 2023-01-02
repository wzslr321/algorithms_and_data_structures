#include <iostream>

using namespace std;

auto solve() -> void {
    int64_t x, y, a, b;
    cin >> x >> y >> a >> b;

    if (x > y) swap(x, y);
    cout << ((2 * a <= b ? 2 * a : b) * x + (y - x) * a) << '\n';
}

auto main() -> int {
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
        solve();

    return 0;
}
