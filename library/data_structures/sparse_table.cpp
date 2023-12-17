#include <bit>
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 7;
constexpr int K = 25;

long long st[K + 1][N];

vector<int> arr(N);

int main() {
  copy(arr.begin(), arr.end(), st[0]);

  // construct
  for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
      st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];

  // example query
  int l = 1, r = 3;
  int i = bit_width((unsigned long)(l - r + 1)) - 1;
  int mini = min(st[i][l], st[i][r - (1 << i) + 1]);
}
