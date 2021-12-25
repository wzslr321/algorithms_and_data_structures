#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

int path[100005];
ll dist[100005];
vector<ll> nodes[100005];
int curr, curr_w, curr_el;
int a, b, w;
map<pair<ll, ll>, ll> edge;
priority_queue<ll> pq;

void print(ll i) {
  if (i != 1) print(path[i]);
  cout << i << ' ';
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  while (m--) {
    cin >> a >> b >> w;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
    edge[make_pair(a, b)] = w;
    edge[make_pair(b, a)] = w;
  }
  LPI(i, 2, n + 1, 1) { dist[i] = 1e18; }
  pq.push(1);
  while (pq.size() > 0) {
    curr = pq.top();
    pq.pop();
    LPI(i, 0, nodes[curr].size(), 1) {
      curr_el = nodes[curr][i];
      curr_w = edge[{curr, curr_el}];
      if (dist[curr] + curr_w < dist[curr_el]) {
        dist[curr_el] = dist[curr] + curr_w;
        path[curr_el] = curr;
        pq.push(curr_el);
      }
    }
  }
  if (dist[n] == 1e18) return cout << -1, 0;
  print(n);

  return 0;
}
