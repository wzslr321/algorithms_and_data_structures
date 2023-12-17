#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

string s;
ll pos;

void solve() {
  cin >> s >> pos;
  --pos;
  int len = s.size();

  vector<char> st;
  bool ok = pos < len;
  s += "$";
  for (auto c : s) {
    while (!ok && st.size() > 0 && st.back() > c) {
      pos -= len, --len;
      st.pop_back();
      if (pos < len) ok = true;
    }
    st.push_back(c);
  }
  cout << st[pos];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}

// pbdtm
// bdtm
// bdm
// m
// d
//
//
//
//
//
