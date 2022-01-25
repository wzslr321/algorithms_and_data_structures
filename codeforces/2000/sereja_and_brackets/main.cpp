#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

constexpr int N = 1e6 * 2 + 9;

vector<int> sgt(N);
string seq;
int queries, l, r;
size_t sgsz, sz;
stack<pair<int, char>> brackets;

auto query() -> int {
  cin >> l >> r;
  int ans = 0;
  --l;
  for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans += sgt[l++];
    if (r & 1) ans += sgt[--r];
  }

  return ans;
}

auto check_stack() -> void {
  if (brackets.size() < 2) return;
  auto curr = brackets.top();
  brackets.pop();
  auto prev = brackets.top();
  if (curr.second == ')' && prev.second == '(') {
    sgt[sz + prev.first] = 1;
    brackets.pop();
    check_stack();
  } else {
    brackets.push(curr);
  }
}

auto build() -> void {
  if (sz & 1) {
    for (size_t i = sz - 1; i >= sz / 2; --i)
      sgt[i] = sgt[i << 1];
  } else {
    for (size_t i = sz - 1; i >= sz / 2; --i)
      sgt[i] = sgt[i << 1 | 1];
  }
  for (int i = (int)(sz / 2) - 1; i > 0; --i)
    sgt[i] = sgt[i << 1] + sgt[i << 1 | 1];
}

auto solve() -> void {
  cin >> seq;
  sz = seq.size();
  sgsz = seq.size() << 1;

  for (size_t i = 0; i < sz; ++i) {
    if (brackets.size() < 1) {
      if (seq[i] == ')')
        continue;
      else
        brackets.push({i, seq[i]});
    }

    bool matched = false;
    auto top = brackets.top();
    if (seq[i] == ')' && top.second == '(') {
      brackets.pop();
      sgt[sz + top.first] = 2;
      matched = true;
      check_stack();
    }
    if (!matched) brackets.push({i, seq[i]});
  }

  build();

  for (size_t i = sz; i < sgsz; ++i) {
    cout << i << ' ';
  }
  cout << '\n';
  for (size_t i = sz; i < sgsz; ++i) {
    cout << sgt[i] << "  ";
  }
  cout << '\n';

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i)
    cout << query() << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
