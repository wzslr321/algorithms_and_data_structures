#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    vector<PI> sft;
    int n;
    cin >> n;
    vector<int> arr(n);
    LPI(i, 0, n, 1) { cin >> arr[i]; }

    LPI(i, 0, n - 1, 1) {
      int mini = i;
      LPI(j, i + 1, n, 1) {
        if (arr[j] < arr[mini]) mini = j;
      }

      if (mini > i) {
        sft.PB({i, mini});
        int found = arr[mini];
        for (int j = mini; j > i; --j)
          arr[j] = arr[j - 1];
        arr[i] = found;
      }
    }
    cout << sft.size() << '\n';
    for (auto p : sft) {
      cout << p.first + 1 << ' ' << p.second + 1 << ' ' << p.second - p.first
           << '\n';
    }
  }

  return 0;
}
