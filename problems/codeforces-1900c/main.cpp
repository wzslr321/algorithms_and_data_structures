#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

typedef pair<int, int> pi;

int n;
string s;
constexpr int N = 3 * 1e5 + 7;

vector<int> left_ch(N);
vector<int> right_ch(N);

int dfs(int x) {
  if (!left_ch[x] && !right_ch[x]) return 0;
  int ans = INT_MAX;
  if (left_ch[x]) ans = min(ans, dfs(left_ch[x]) + (s[x - 1] != 'L'));
  if (right_ch[x]) ans = min(ans, dfs(right_ch[x]) + (s[x - 1] != 'R'));
  return ans;
}

void solve() {
  cin >> n >> s;
  rep(i, 1, n + 1) cin >> left_ch[i] >> right_ch[i];
  cout << dfs(1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}

