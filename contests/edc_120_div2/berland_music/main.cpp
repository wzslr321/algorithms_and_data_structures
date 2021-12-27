#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

const int N = 2 * 10e5 + 1;
int arr[N];

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<int, bool> liked;
    unordered_map<int, bool> psb;
    LPI(i, 0, n, 1) { cin >> arr[i]; }
    string s;
    cin >> s;
    int l = 0;
    LPI(i, 0, n, 1) {
      if (s[i] == '1') {
        liked[i] = true, ++l;
      }
    }
    int diff = n - l;
    LPI(i, diff + 1, n + 1, 1) { psb[i] = true; }
    int j = 1;
    LPI(i, 0, n, 1) {
      if (liked[i] == true) {
        int best = INT_MAX;
        int pick = 0;
        for (const auto &[key, value] : psb) {
          if (value != true) continue;
          if (abs(arr[i] - key) < best) {
            best = abs(arr[i] - key), pick = key;
          }
        }
        arr[i] = pick;
        psb[pick] = false;
      } else {
        arr[i] = j, j++;
      }
    }
    LPI(i, 0, n, 1) { cout << arr[i] << ' '; }
    cout << '\n';
  }

  return 0;
}
