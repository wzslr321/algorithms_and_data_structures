#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
int maxProfit(vector<int> &prices) {
  int min{prices[0]}, max{0}, inmin{0};
  int cr_pr{};
  for (auto i{1}; i < prices.size(); i++) {
    if (prices[i] < min) {
      min = prices[i];
      inmin = i;
      max = 0;
    }
    if (prices[i] > max && i > inmin) max = prices[i];
    if (max - min > cr_pr) {
      cr_pr = max - min;
    }
  }
  return cr_pr > 0 ? cr_pr : 0;
}

int main() {
  vector<int> p1{7, 1, 5, 3, 6, 4}; // 5
  vector<int> p2{7, 6, 4, 3, 1};    // 0
  vector<int> p3{1, 2};             // 1
  vector<int> p4{2, 4, 1};          // 2

  cout << maxProfit(p1) << '\n';
  cout << maxProfit(p2) << '\n';
  cout << maxProfit(p3) << '\n';
  cout << maxProfit(p4) << '\n';

  return 0;
}
