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

int N;

auto solve() -> void {
  cin >> N;
  vector<int> arr(N);
  LPI(i, 0, N, 1) cin >> arr[i];
  sort(arr.begin(), arr.end(), greater<int>());
  LPI(i, 0, 10, 1) { cout << arr[i] << ' '; }
  cout << '\n';
  // vector<int> answer;
  /*
  bool used[N];
  while (answer.size() < 10) {
    // cout << "XD";
    int max_v = INT_MIN;
    int max_i;
    LPI(i, 0, N, 1) {
      if (used[i] != true && arr[i] >= max_v) max_v = arr[i], max_i = i;
    }
    cout << max_v << '\n';
    used[max_i] = true;
    answer.PB(max_v);
  }
  sort(answer.begin(), answer.end(), greater<int>());
  // for (auto el : answer)
  // cout << el << ' ';
  cout << '\n';
  */
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
