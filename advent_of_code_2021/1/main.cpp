#include <climits>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int {
  int larger = 0;
  int prev = INT_MAX;
  while (cin) {
    int curr;
    cin >> curr;
    if (curr > prev) ++larger;
    prev = curr;
    if (curr == -1) break;
  }
  cout << larger << '\n';

  return 0;
}
