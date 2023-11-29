#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void solve() {
    int c,m,x;
    cin >> c >> m >> x;
    
    int l = 0, r = 10e8;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(c >= mid && m >= mid && (x + (c - mid) + (m - mid)) >= mid) {
            l = mid + 1; 
        } else {
            r = mid;
        }
    }

    cout << l - 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
