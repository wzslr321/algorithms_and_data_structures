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

const int N = 2 * 10e5 + 1;
vector<pair<int, int>> tree(N);
vector<int> parent(N);
string c;
int n, k;
int dp = 0;

string ans = "";
auto scan(int node) -> void {
  stack<int> left;
  queue<int> right;
  int current = node;
  left.push(1);
  while (tree[current].first != 0) {
    current = tree[current].first;
    left.push(current);
  }
  current = node;
  while (tree[current].second != 0) {
    current = tree[current].second;
    right.push(current);
  }
  while (left.size() > 0) {
    int curr = left.top();
    left.pop();
    ans += c[curr - 1];
    if ((curr == 1 || c[parent[curr] - 1] == c[curr - 1]) && dp < k) {
      bool worth = true;
      LPI(i, curr, n, 1) {
        if (c[i] < c[curr - 1]) {
          worth = false;
          break;
        }
      }
      if (worth) {
        ans += c[curr - 1];
        ++dp;
      }
    }
  }
  while (right.size() > 0) {
    int curr = right.front();
    right.pop();
    ans += c[curr - 1];
    if ((curr == 1 || c[parent[curr] - 1] == c[curr - 1]) && dp < k) {
      bool worth = true;
      LPI(i, curr, n, 1) {
        if (c[i] < c[curr - 1]) {
          worth = false;
          break;
        }
      }
      if (worth) {
        ans += c[curr - 1];
        ++dp;
      }
    }
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> c;
  LPI(i, 1, n + 1, 1) {
    int l, r;
    cin >> l >> r;
    tree[i] = make_pair(l, r);
    parent[l] = i, parent[r] = i;
  }
  scan(1);

  cout << ans << '\n';

  return 0;
}
/*
ans += c[node - 1];
if (node == 1 || c[parent[node]] == c[node - 1]) {
  bool worth = true;
  LPI(i, node, n, 1) {
    if (c[i] < c[node - 1]) {
      worth = false;
      break;
    }
  }
  if (worth) {
    ans += c[node - 1];
  }
}
*/
