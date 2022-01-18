#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

const int N = (1 << 17) + 7;
int seq[2 * N];
int n, m;
int p, b;
int seq_size;

auto query() -> void { cin >> p >> b; }

auto build_ors() -> void {
  for (int i = seq_size - 1; i >= seq_size / 2; --i) {
    seq[i] = seq[i << 1] | seq[i << 1 | 1];
    cout << "OR: " << seq[i] << ' ' << i << '\n';
  }
}

auto build_xors() -> void {
  for (int i = (seq_size / 2) - 1; i >= 1; --i) {
    seq[i] = seq[i << 1] ^ seq[i << 1 | 1];
  }
}

auto solve() -> void {
  cin >> n >> m;
  seq_size = 1 << n;

  for (int i = (1 << n); i < 2 * (1 << n); ++i)
    cin >> seq[i];
  build_ors();
  build_xors();

  while (m--)
    query();
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
