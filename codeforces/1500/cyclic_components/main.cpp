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

const int N = 2 * 1e5 + 7;
int n, m;
unordered_map<int, vector<int>> ver;
bool visited[N];
int ans = 0;
int v_count = 0;

auto dfs(int s) -> void {
  stack<int> st;
  st.push(s);
  bool bad = false;
  while (!st.empty()) {
    auto curr = st.top();
    st.pop();
    if (visited[curr] == true) continue;
    ++v_count, visited[curr] = true;
    if (ver[curr].size() != 2) bad = true;
    for (auto e : ver[curr]) {
      if (!visited[e]) st.push(e);
    }
  }
  if (!bad) ++ans;
}

auto solve() -> void {
  cin >> n >> m;
  LPI(i, 0, m, 1) {
    int v, u;
    cin >> v >> u;
    ver[v].PB(u);
    ver[u].PB(v);
  }
  int last = 1;
  while (v_count < n) {
    for (int i = last; i <= n; ++i) {
      if (visited[i] != true) {
        last = i;
        dfs(i);
        break;
      }
    }
  }
  cout << ans << '\n';
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
