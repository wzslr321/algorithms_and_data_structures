#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VVI = vector<vector<int>>;
using VS = vector<string>;
using PI = pair<int, int>;

void print_matrix(const VVI &matrix) {
  LPI(i, 0, matrix.size(), 1) {
    LPI(j, 0, matrix.size(), 1) { cout << matrix[i][j] << ' '; }
    cout << endl;
  }
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << '1' << endl;
    }
    if (n == 2) {
      cout << "-1" << endl;
    }
    int least = 1;
    int second = 0;
    VVI matrix;
    LPI(i, 0, n, 1) {
      VI row{least};
      if (i == 0) {
        LPI(j, 1, n, 1) { row.PB(least + j * 2); }
        second = row[n - 1] - 1;
      } else {
        row.PB(second);
        LPI(j, 2, n, 1) { row.PB(second + (j - 1) * 2); }
        second = row[n - 1] - 1;
      }
      matrix.PB(row);
    }
    matrix[0][0] = matrix[n - 1][n - 1];
    matrix[n - 1][n - 1] = 1;

    print_matrix(matrix);
  }

  return 0;
}
