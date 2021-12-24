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

int N, K;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;

  vector<int> arr(N);
  vector<pair<int, int>> sorted(N);
  vector<int> teams(N);
  vector<bool> used(N);

  LPI(i, 0, N, 1) {
    cin >> arr[i];
    sorted[i] = make_pair(arr[i], i);
  }

  sort(sorted.begin(), sorted.end(),
       [](pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; });
  int usedels = 0;
  int curr = 0;

  int prev = 2;
  while (usedels < N) {
    int picked = sorted[curr].second;
    if (used[picked] == true) {
      ++curr;
      continue;
    }

    if (prev == 2) {
      prev = 1;
      teams[picked] = 1;
      ++usedels;
      int lk = K;
      LPI(i, 1, lk + 1, 1) {
        if (picked - i < 0) break;
        if (used[picked - i]) {
          ++lk;
          continue;
        }
        teams[picked - i] = 1;
        used[picked - i] = true;
        ++usedels;
      }
      lk = K;
      LPI(i, 1, lk + 1, 1) {
        if (picked + i >= N) break;
        if (used[picked + i]) {
          ++lk;
          continue;
        }
        teams[picked + i] = 1;
        used[picked + i] = true;
        ++usedels;
      }
    } else {
      prev = 2;
      teams[picked] = 2;
      ++usedels;
      int lk = K;
      LPI(i, 1, lk + 1, 1) {
        if (picked - i < 0) break;
        if (used[picked - i]) {
          ++lk;
          continue;
        }
        teams[picked - i] = 2;
        used[picked - i] = true;
        ++usedels;
      }
      lk = K;
      LPI(i, 1, lk + 1, 1) {
        if (picked + i >= N) break;
        if (used[picked + i]) {
          ++lk;
          continue;
        }
        teams[picked + i] = 2;
        used[picked + i] = true;
        ++usedels;
      }
    }
    used[picked] = true;
    ++curr;
  }

  LPI(i, 0, N, 1) { cout << teams[i]; }

  cout << '\n';

  return 0;
}
