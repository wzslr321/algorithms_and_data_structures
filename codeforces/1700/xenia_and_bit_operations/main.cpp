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

// const int N = (1 << 17) + 7;
int seq_size;
vector<int> seq(1 << 18);

auto modify(int p, int b) -> void {
  seq[p += seq_size - 1] = b;
  seq[p >> 1] = seq[p] | seq[p ^ 1];
  p >>= 1;
  for (; p > 1; p >>= 1) {
    seq[p >> 1] = seq[p] ^ seq[p ^ 1];
  }
}

auto solve() -> void {
  int n, m;
  cin >> n >> m;
  seq_size = 1 << n;

  for (int i = seq_size; i < (seq_size << 1); ++i)
    cin >> seq[i];
  for (int i = seq_size - 1; i >= seq_size / 2; --i) {
    seq[i] = seq[i << 1] | seq[i << 1 | 1];
  }
  for (int i = (seq_size / 2) - 1; i >= 1; --i) {
    seq[i] = seq[i << 1] ^ seq[i << 1 | 1];
  }

  while (m--) {
    int p, b;
    cin >> p >> b;
    modify(p, b);
    cout << seq[1] << '\n';
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
