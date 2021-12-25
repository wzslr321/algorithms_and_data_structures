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
    LPI(i, 0, edges[curr].size(), 1) {
      if (edges[curr][i] < curr) continue;
      st.push(edges[curr][i]);
    }
  }
  return ile;
}

int czerw = 0;

const int N = 2 * 10e5;
bool uzyte[N];
bool leaf[N];

int wczesniej = 2 * 10e5 + 1;

void liscie() {
  bool bylem[N];
  queue<int> st;
  st.push(teraz - 1);
  while (st.size() > 0) {
    auto tera = st.front();
    bylem[tera] = true;
    st.pop();
    if (edges[tera].size() == 1 && !uzyte[tera]) {
      if (edges[edges[tera][0]].size() > 1) {
        uzyte[tera] = true;
        if (tera > wczesniej && czerw >= k) {
          uzyte[wczesniej] = false;
          --czerw;
        }
        ++czerw;
        wczesniej = tera;
        continue;
      }
    }
    if (uzyte[edges[tera][0]]) {
      if (edges[edges[tera][0]].size() > 1) {
        uzyte[tera] = true;
        if (tera > wczesniej && czerw >= k) {
          uzyte[wczesniej] = false;
          --czerw;
        }
        wczesniej = tera;
        ++czerw;
        continue;
      }
    }
    LPI(i, 0, edges[tera].size(), 1) {
      if (bylem[edges[tera][i]]) continue;
      st.push(edges[tera][i]);
    }
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
    LPI(i, 0, edges[curr].size(), 1) {
      if (edges[curr][i] < curr) continue;
      st.push(edges[curr][i]);
    }
  }
  return ile;
}

int najlepsze() {
  queue<int> qq;
  qq.push(1);
  int ile = 0;
  while (qq.size() > 0) {
    auto tera = qq.front();
    qq.pop();
    LPI(i, 0, edges[tera].size(), 1) {
      if (edges[tera][i] < tera) continue;
      qq.push(edges[tera][i]);
    }
    int res = ile_moge(tera);
    if (res > 0) ile += res;
  }
  return ile;
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  bool root[n];
  LPI(i, 1, n, 1) {
    int u, v;
    cin >> u >> v;
    edges[u].PB(v);
    edges[v].PB(u);
  }
  if (k >= n) {
    cout << (n / 2) * (n / 2);
    return 0;
  }
  if (k == 1 && n == 2) {
    cout << "1";
    return 0;
  }

  while (sumuj(teraz) > k) {
    ++teraz;
  }

  liscie();
  if (czerw < k) {
  }
  auto nieb = najlepsze();
  cout << (n - (czerw + nieb)) * (czerw - nieb);

  return 0;
}
