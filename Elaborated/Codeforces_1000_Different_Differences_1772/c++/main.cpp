#include <iostream>
#include <vector>

using namespace std;

auto print_arr(const vector<int> &arr) -> void {
    for (const auto num: arr)
        cout << num << ' ';
    cout << '\n';
}

auto solve() -> void {
    int k, n;
    cin >> k >> n;

    vector<int> arr(k);
    arr[0] = 1, arr[1] = 2; // k >= 2
    for (int i = 2; i < k; ++i) {
        auto desired = 2 * arr[i - 1] - arr[i - 2] + 1;
        if (n - desired >= k - i - 1) {
            arr[i] = desired;
            continue;
        }

        // can't increase further, fill the rest
        while (i < k) {
            arr[i] = arr[i - 1] + 1;
            ++i;
        }
    }

    print_arr(arr);
}


auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests_count = 1;
    cin >> tests_count;
    while (tests_count--)
        solve();

    return 0;
}
