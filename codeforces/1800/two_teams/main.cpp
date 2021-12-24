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
  int N, K;

  cin >> N >> K;

  int arr[N];
  bool used[N];
  priority_queue<pair<int, int>> pq;
  int teams[N];

  LPI(i, 0, N, 1) {
    cin >> arr[i];
    pq.push({arr[i], i});
    used[i] = false;
  }

  int usedels = 0;
  int now = 1;

  while (usedels < N) {
    while (used[pq.top().second]) {
      pq.pop();
    }
    int picked = pq.top().second;
    pq.pop();
    used[picked] = true;

    teams[picked] = now;
    ++usedels;
    int lk = K;
    LPI(i, 1, lk + 1, 1) {
      if (picked - i < 0) break;
      if (used[picked - i]) {
        ++lk;
        continue;
      }
      teams[picked - i] = now;
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
      teams[picked + i] = now;
      used[picked + i] = true;
      ++usedels;
    }
    if (now == 1)
      now = 2;
    else
      now = 1;
  }

  for (auto el : teams) {
    cout << el;
  }

  return 0;
}
