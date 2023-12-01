#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  int highest_bit = 0;
  for (int i = 0; i < 31; i++)
    if ((n - 1) & (1 << i)) highest_bit = i;
  int h = 1 << highest_bit;
  for (int i = h - 1, j = 0; i >= 0; --i, ++j)
    vec[j] = i;
  for (int i = h; i < n; ++i)
    vec[i] = i;

  for (const auto v : vec)
    cout << v << ' ';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}

/*

   [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

   0 0 0 0
   0 0 0 1
   0 0 1 0
   0 0 1 1
   0 1 0 0
   0 1 0 1
   0 1 1 0
   0 0 0 1
   0 1 1 1
   0 0 0 0
   1 0 0 0
   1 0 0 1

   0 1 1 1
   0 1 1 0


 */
