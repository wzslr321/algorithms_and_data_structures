#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

constexpr int N = 1e5 + 7;

vector<int> costs(N);
vector<int> afraid(N);
vector<vector<int>> scares(N, vector<int>());

vector<int> conf(N);
vector<int> conb(N);
vector<int> dp(N);

int n;
int last = -1;

void connect(int a) {
  if (dp[a]) return;
  if (scares[a].size() == 0) {
    conf[a] = afraid[a], conb[afraid[a]] = a;
    dp[a] = 1;
  }

  for (auto s : scares[a]) {
    if (afraid[a] != s || afraid[s] != a) {
      connect(s);
    } else {
      costs[a] > costs[s] ? conf[a] = s, conb[s] = a : conf[s] = a, conb[a] = s;
      dp[a] = 1;
      dp[s] = 1;
    }
  }
}

void solve() {
  cin >> n;
  rep(i, 1, n + 1) {
    cin >> afraid[i];
    scares[afraid[i]].push_back(i);
  }
  rep(i, 1, n + 1) cin >> costs[i];

  rep(i, 1, n + 1) connect(i);

  cout << "connections forward:\n";
  rep(i, 1, n + 1) cout << i << ' ' << conf[i] << '\n';

  cout << "connections backward:\n";
  rep(i, 1, n + 1) cout << i << ' ' << conb[i] << '\n';

  /*
rep(i, 1, n + 1) {
stack<int> st;
int curr = i;
st.push(curr);
while (con[curr]) {
st.push(con[curr]);
curr = con[curr];
}
while (!st.empty()) {
cout << st.top() << ' ';
st.pop();
}
}
*/

  /*
  cout << '\n';
  for(int i = 1; i < n + 1; i++ ){
      cout << i << " scares: ";
      for(int j = 0; j < scares[i].size(); j++) {
          cout << scares[i][j] << ' ';
      }
      cout << '\n';
  }
  */
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
