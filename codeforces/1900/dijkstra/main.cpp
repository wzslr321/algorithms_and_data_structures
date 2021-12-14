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
  if (!a || !b) return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}

template <typename T> T LCM(T a, T b) { return a / GCD(a, b) * b; }

int path[100005];
ll dist[100005];
vector<ll> nodes[100005];
int curr,curr_w, curr_el;
int a, b, w;
map<pair<ll,ll>, ll> edge;
priority_queue<ll> pq;

void print(ll i) {
    if(i != 1) print(path[i]);
    cout << i << ' ';
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  while(m--) {
    cin >> a >> b >> w;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
    edge[make_pair(a,b)] = w;
    edge[make_pair(b,a)] = w;
  }
  LPI(i,2,n+1,1) {
      dist[i] = 1e18;
  }
  pq.push(1);
  while(pq.size() > 0) {
      curr = pq.top();
      pq.pop();
      LPI(i,0,nodes[curr].size(), 1) {
          curr_el = nodes[curr][i];
          curr_w = edge[{curr,curr_el}];
          if(dist[curr] + curr_w < dist[curr_el]) {
              dist[curr_el] = dist[curr] + curr_w;
              path[curr_el] = curr;
              pq.push(curr_el);
          }
      }
  }
  if(dist[n] == 1e18) return cout << -1, 0;
  print(n);

  return 0;
}