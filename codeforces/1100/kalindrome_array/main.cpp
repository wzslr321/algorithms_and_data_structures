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

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    LPI(i, 0, n, 1) { cin >> arr[i]; }
    int j = n - 1;
    int i = 0;
    int del[2];
    bool ans = true;
    while (i < j) {
      if (arr[i] != arr[j]) {
        del[0] = arr[i];
        del[1] = arr[j];
        break;
      }
      --j;
      ++i;
    }
    bool inn = true;
    int si = i;
    int sj = j;
    while (i < j && inn) {
      if (arr[i] != arr[j]) {
        if (arr[i] == del[0]) {
          ++i;
          continue;
        }
        if (arr[j] == del[0]) {
          --j;
          continue;
        }
        inn = false;
      }
      ++i;
      --j;
    }
    while (!inn && si < sj && ans) {
      if (arr[si] == del[1]) {
        ++si;
        continue;
      }
      if (arr[sj] == del[1]) {
        --sj;
        continue;
      }
      ans = false;
      ++si;
      --sj;
    }
    ans || inn ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
