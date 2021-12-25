#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 2;

  // before n, for the first n ( i in while loop)
  // it is always 2
  int b_n{2};
  // as above, just before before.
  int bb_n{1};
  int current{};
  int i{3};
  while (i <= n) {
    current = b_n + bb_n;
    bb_n = b_n;
    b_n = current;
    i++;
  }

  return current;
}

int main() {
  cout << climbStairs(1) << '\n';
  cout << climbStairs(3) << '\n';
  cout << climbStairs(4) << '\n';

  return 0;
}
