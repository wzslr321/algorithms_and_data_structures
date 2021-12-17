#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i{a}; i < b; i += d)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;

int arr[2000];
int trans[2000][2000];

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    int n,q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      trans[0][i] = arr[i];
    }
    cin >> q;
    int ts = 1;
    LPI(i, 0, n, 1) {
      unordered_map<int, int> mpi;
      for (int j = 0; j < n; ++j) {
        ++mpi[arr[j]];
      }
      for (int j = 0; j < n; ++j) {
        arr[j] = mpi[arr[j]];
        trans[ts][j] = arr[j];
      }
      ++ts;
    }
    while (q--) {
      int x,k;
      cin >> x >> k;
      k = min(k, n);
      cout << trans[k][x - 1] << '\n';
    }
  }

  return 0;
}
