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

int n;
ll total = 0ll;
vector<int> arr;

bool ok(ll a) {
  int l = 0, r = n - 1;
  ll sum = 0ll, moves = 0ll, x = 0ll;
  int lol = 0;
  while (l < r) {
    // kill mf with ulti
    if (x == arr[r]) {
      sum += arr[r], ++moves;
      --r, x = 0;
      continue;
    }

    // kill mf by hits
    int add = lol ? lol : arr[l];
    if (x + add < arr[r]) {
      sum += add;
      moves += add;
      x += add;
      ++l;
      lol = 0;
      continue;
    }

    // hit mf with hits and maybe kill
    int need = arr[r] - x;
    sum += need;
    moves += need;
    x += need;
    lol = arr[l] - need;

    if (arr[l] - need == 0) ++l;
  }

  // kill optimally whats left
  int left = total - sum;
  int need = ceil((left - x) / 2.) + 1;
  if (left == 1) need = 1;

  return moves + need <= a;
}

void solve() {
  cin >> n;
  total = 0ll;
  arr.assign(n, 0);
  rep(i, 0, n) cin >> arr[i], total += arr[i];
  sort(arr.begin(), arr.end());
  ll l = 0ll, r = total;
  while (l < r) {
    ll mid = l + (r - l) / 2ll;
    if (ok(mid))
      r = mid;
    else
      l = mid + 1ll;
  }
  cout << l << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
