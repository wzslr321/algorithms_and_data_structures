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

unordered_map<int, vector<int>> edges;
int n, k;

int teraz = 1;
int sumuj(int tera) {
  stack<int> st;
  st.push(tera);
  int ile = 0;
  while (st.size() > 0) {
    auto curr = st.top();
    st.pop();
    ++ile;
    LPI(i, 0, edges[curr].size(), 1) { st.push(edges[curr][i]); }
  }
  return ile;
}

int czerw = 0;

const int N = 2 * 10e5;
bool uzyte[N];
void liscie() {
  stack<int> st;
  st.push(teraz - 1);
  while (st.size() > 0) {
    if (czerw == k) break;
    auto tera = st.top();
    st.pop();
    if (edges[tera].size() == 0 && !uzyte[tera]) {
      uzyte[tera] = true;
      ++czerw;
      continue;
    }
    if (uzyte[edges[tera][0]]) {
      uzyte[tera] = true;
      ++czerw;
      continue;
    }
    LPI(i, 0, edges[tera].size(), 1) { st.push(edges[tera][i]); }
  }
}

int ile_moge(int root) {
  stack<int> st;
  st.push(root);
  int ile = 0;
  while (st.size() > 0) {
    auto curr = st.top();
    if (uzyte[curr]) return 0;
    st.pop();
    ++ile;
    LPI(i, 0, edges[curr].size(), 1) { st.push(edges[curr][i]); }
  }
  return ile;
}

int najlepsze() {
  queue<int> qq;
  qq.push(1);
  int best = INT_MIN;
  while (qq.size() > 0) {
    auto tera = qq.front();
    qq.pop();
    LPI(i, 0, edges[tera].size(), 1) { qq.push(edges[tera][i]); }
    best = max(best, ile_moge(tera));
  }
  return best;
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  LPI(i, 1, n, 1) {
    int u, v;
    cin >> u >> v;
    edges[u].PB(v);
    edges[v];
  }

  while (sumuj(teraz) > k) {
    ++teraz;
  }

  liscie();
  auto nieb = najlepsze();
  cout << (n - (czerw + nieb)) * (czerw - nieb);

  return 0;
}
