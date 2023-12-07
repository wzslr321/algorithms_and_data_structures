#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iomanip>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

// isnt in a or b => cant
// is in a && start is in a -> can
// is in b && start is in b -> can
// is in b && start is in a && a and b overlap
// is in a && start is in b && a and b overlap
// overlap = |AB| <= 2w
// is in -> |[A/B]P| <= w
// starts in -> |[A/B]0| <= w

typedef pair<int, int> pi;

pi h, fl, sl;
pi start = {0, 0};

double dist(pi p1, pi p2) {
  return sqrt(pow((p1.first - p2.first), 2) +
              pow((p1.second - p2.second), 2));
}

bool can(ld w) {
  bool startInA = dist(start, fl) <= w;
  bool startInB = dist(start, sl) <= w;
  bool houseInA = dist(h, fl) <= w; // {3, 3} {1, 0}
  bool houseInB = dist(h, sl) <= w;
  bool overlap = dist(sl, fl) <= 2. * w;

  // cout << "dist: " << dist({3, 3}, {1,0}) << '\n';

  if (!houseInA && !houseInB) return false;
  if (startInA && houseInA) return true;
  if (startInB && houseInB) return true;
  if (startInA && houseInB && overlap) return true;
  if (startInB && houseInA && overlap) return true;

  return false;
}

void solve() {
  int h1, h2, l1, l2, l3, l4;
  cin >> h1 >> h2 >> l1 >> l2 >> l3 >> l4;
  h = {h1, h2};
  fl = {l1, l2};
  sl = {l3, l4};
  ld l = 0.0L, r = 2.L * 10e3;
  while (r - l > 1e-7L) {
    ld mid = l + (r - l) / 2.L;
    if (can(mid))
      r = mid;
    else
      l = mid;
  }
  cout << fixed << l << setprecision(7) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}

