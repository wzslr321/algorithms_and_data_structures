#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  VS arr(n);
  LPI(i, 0, n, 1) { cin >> arr[i]; }
  sort(arr.begin(), arr.end(),
       [](string a, string b) { return a.size() < b.size(); });

  bool ans = true;
  LPI(i, 0, n - 1, 1) {
      if(arr[i + 1].find(arr[i]) == string::npos) {
          ans = false;
          break;
      }
  }

  if (!ans) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";

  for (auto el : arr) {
    cout << el << '\n';
  }

  return 0;
}
