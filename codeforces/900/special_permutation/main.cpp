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

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
      int n,a,b;
      cin >> n >> a >> b;
      VI nums;
      for(int i = n; i > n/2; --i) {
          if(i != b && i != a) {
            if(a == min(a,i)) {
                nums.PB(i);
            }
          }
      }
      if(nums.size() == n/2) {
          cout << "-1\n";
          continue;
      }
      nums.PB(a);
      if(nums.size() < n/2) {
          cout << "-1\n";
          continue;
      }
      nums.PB(b);
      for(int j = n/2; j > 0; --j) {
           if(j != a && j != b) {
                if(b == max(b,j)) {
                    nums.PB(j);
                }
           }
      }
      if(nums.size() == n) {
        LPI(i,0,n,1){
            cout << nums[i] << ' ';
        }
      } else {
          cout << "-1";
      }

      cout << '\n';
  }

  return 0;
}
