#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

int n, a, b, c;
string s;
/*
  if (z_count == 0 && o_count == 0 && d_count == 0) {
    wyrzuc_zero();
    licz();
  }
  if (z_count == 0 && o_count > 0 && d_count == 0 && curr == 2) {
    wyrzuc_zero();
    licz();
  }
  if (z_count > 0 && o_count == 0 && d_count == 0 && curr == 1) {
    wyrzuc_zero();
    licz();
  }
  */

const int N = 10e5 + 7;
vector<bool> visited(N);

int z_count = 0;
int o_count = 0;
int d_count = 0;

int curr = -1;

ll ans = 0ll;

void wyrzuc_zero() {
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;
    int j = i;
    if (s[i] == '0') {
      while (visited[j])
        --j;
      if (s[j] == '0') {
        cout << "KURWA";
        visited[j] = true, ++d_count;
      }
    }
  }
}

auto szukaj() -> void {
  LPI(i, 0, n, 1) {
    if (visited[i]) continue;
    if (s[i] == '0' && curr != 1) {
      int j = i + 1;
      while (j < n - 1 && visited[j])
        ++j;
      if (s[j] == '0') {
        visited[i] = true, ++z_count;
        break;
      }
    }
    if (s[i] == '1' && curr != 2) {
      int j = i + 1;
      while (j < n - 1 && visited[j])
        ++j;
      if (s[j] == '1') {
        visited[i] = true, ++o_count;
        break;
      }
    }
  }
}

auto licz() -> bool {
  if (z_count > 0 && curr != 1) {
    curr = 1, ans += a, --z_count;
    cout << "Zastąp zera\n";
    cout << "Nowy string: ";
    LPI(i, 0, n, 1) {
      if (visited[i]) continue;
      cout << s[i];
    }
    cout << '\n';
    return true;
  }
  if (o_count > 0 && curr != 2) {
    curr = 2, ans += b, --o_count;
    cout << "Zastąp jedynki\n";
    cout << "Nowy string: ";
    LPI(i, 0, n, 1) {
      if (visited[i]) continue;
      cout << s[i];
    }
    cout << '\n';
    return true;
  }
  if (curr != 3 && d_count > 0) {
    if (z_count <= 0 && o_count <= 0) return false;
    curr = 3, ans -= c, --d_count;
    cout << "Wyrzuc zero\n";
    return true;
  }
  int xd = z_count, xdd = o_count, xddd = d_count;
  szukaj();
  if (xd == z_count && xdd == o_count && xddd == d_count) {
    wyrzuc_zero();
    szukaj();
  }

  return false;
}

void zeruj() {
  z_count = 0;
  o_count = 0;
  d_count = 0;
  fill(visited.begin(), visited.end(), false);
  curr = -1;
  ans = 0;
}

auto solve(int opt) -> void {
  zeruj();
  LPI(i, 0, s.size() - 1, 1) {
    if (opt == 1) {
      if (s[i] == '1' && s[i + 1] == '1') {
        ++o_count, ++i, visited[i] = true;
        break;
      }
    } else {
      if (s[i] == '0' && s[i + 1] == '0') {
        ++z_count, ++i, visited[i] = true;
        break;
      }
    }
  }
  while (licz())
    licz();
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--) {
    cin >> n >> a >> b >> c >> s;
    solve(1);
    ll lans = ans;
    cout << "=============\n";
    solve(2);
    cout << "First option: " << lans << " second option: " << ans << '\n';
    cout << "Answer " << max(lans, ans) << '\n';
  }

  return 0;
}
