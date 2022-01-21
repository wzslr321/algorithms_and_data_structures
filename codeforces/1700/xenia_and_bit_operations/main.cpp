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
  bool isor = true;
  for (; p > 1; p >>= 1) {
    if (isor) {
      seq[p >> 1] = seq[p] | seq[p ^ 1];
      isor = false;
    } else {
      seq[p >> 1] = seq[p] ^ seq[p ^ 1];
      isor = true;
    }
  }
}

auto solve() -> void {
  int n, m;
  cin >> n >> m;
  seq_size = 1 << n;

  for (int i = 0; i < seq_size; ++i)
    cin >> seq[seq_size + i];

  bool isor = true;
  int curr = seq_size;
  while (curr > 1) {
    for (int i = curr - 1; i >= curr / 2; --i) {
      if (isor) {
        seq[i] = seq[i << 1] | seq[i << 1 | 1];
      } else {
        seq[i] = seq[i << 1] ^ seq[i << 1 | 1];
      }
    }
    isor = !isor;
    curr >>= 1;
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
