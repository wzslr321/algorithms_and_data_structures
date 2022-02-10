#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

VI nums{1, 7, 3, 6, 5, 6};

auto solve() -> int {
  auto sum_left = 0, sum_right = 0;
  if (nums.size() < 3) return -1;
  size_t in = 0;
  for (size_t i = 1; i < nums.size(); ++i)
    sum_right += nums[i];

  while (in < nums.size() - 1 && sum_left != sum_right)
    sum_left += nums[in], sum_right -= nums[++in];

  return sum_left == sum_right ? in : -1;
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << solve() << '\n';

  return 0;
}
