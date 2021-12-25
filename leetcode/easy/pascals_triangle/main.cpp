#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> v1{{1}};
  vector<vector<int>> v{{1}, {1, 1}};
  if (numRows == 1) return v1;
  if (numRows == 2) return v;
  uint row{1};
  while (v.size() < numRows) {
    vector<int> nv{1};
    uint tmp{0};
    for (auto i{1}; i < v[row].size(); i++) {
      nv.push_back(v[row][tmp] + v[row][tmp + 1]);
      ++tmp;
    }
    nv.push_back(1);
    v.push_back(nv);
    row++;
  }

  return v;
}

int main() {
  generate(5);

  return 0;
}
