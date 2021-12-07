#include <iostream>
#include <vector>

using namespace std;

int finalValueAfterOperations(vector<string> &operations) {
  int ans = 0;
  for (size_t i = 0; i < operations.size(); ++i) {
    if (operations[i][1] == '-')
      ++ans;
    else
      --ans;
  }
  return ans;
}

int main() {}
