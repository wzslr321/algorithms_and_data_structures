#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int findJudge(int n, vector<vector<int>> &trust) {
  if (n == 1 && trust.size() == 0) return 1;
  unordered_set<int> invalid;
  unordered_map<int, int> trusted;

  for (size_t i = 0; i < trust.size(); ++i) {
    invalid.insert(trust[i][0]);
    ++trusted[trust[i][1]];
  }
  for (const auto &el : trusted) {
    if (el.second == n - 1) {
      bool impostor = false;
      for (size_t i = 0; i < invalid.size(); ++i) {
        if (invalid.find(el.first) != invalid.end()) {
          impostor = true;
          break;
        }
      }
      if (!impostor) return el.first;
    }
  }
  return -1;
}

int main() {

  vector<vector<int>> trust{{1, 2}};

  cout << findJudge(4, trust) << '\n';

  return 0;
}
