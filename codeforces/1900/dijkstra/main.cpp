#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

#define ll long long
#define ld long double
#define u unsigned

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)
#define LPD(i, a, b, d) for (int i = a; i > b; i -= d)
#define REP(n) for (int i = 0; i < n; ++i)

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;

#define ZEROS_B(x) __builtin_clz(x)
#define ZEROS_E(x) __builtin_ctz(x)

constexpr double pi = acos(-1);
constexpr int mod = 998244353;
constexpr double eps = 1e-10;
constexpr int N = 1e2 + 10;

template <typename T> T gcd(T a, T b) {
  if (!a || !b)
    return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b)
      swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}

template <typename T> T LCM(T a, T b) { return a / GCD(a, b) * b; }

struct Edge {
    int from;
    int to;
    int weight;
    Edge() : from(0), to(0), weight(0) {}
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

int dijkstra(vector<Edge> adj[], int n, int s) {
  bool visited[n + 1];
  fill_n(visited,n+1, false);
  int dist[n + 1];
  fill_n(dist, n+1, INT_MAX);
  dist[1] = 0;

  priority_queue<pair<int,int>> pq;
  pq.push(make_pair(s,0));
  while(pq.size() > 0) {
      int i = pq.top().first;
      int min = pq.top().second;
      pq.pop();
      for(const auto &edge : adj[i]){
          if(visited[edge.to]) continue;
          auto ndist = dist[i] + edge.weight;
          if(ndist < dist[edge.to]) {
            dist[edge.to] = ndist;
            pq.push(make_pair(edge.to, ndist));
          }
      }
  }
 
  LPI(i,1,n + 1,1) {
      cout << dist[i] << ' ';
  }

  return 0;
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  vector<Edge> adj[n+1];

  LPI(i,0,m,1) {
      int a,b,w;
      cin >> a >> b >> w;
      adj[a].push_back(Edge(a,b,w));
      adj[b].push_back(Edge(b,a,w));
  }

  int length = dijkstra(adj, n, 1);
  cout << length << '\n';

  return 0;
}
