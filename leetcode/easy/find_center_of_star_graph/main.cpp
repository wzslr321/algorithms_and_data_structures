#include <vector>

using namespace std;

class Solution {
 public:
  int findCenter(vector<vector<int>> &edges) {
    int p1 = edges[0][0];
    int p2 = edges[0][1];

    for (size_t i = 1; i < edges.size(); ++i) {
      for (size_t j = 0; j < edges[i].size(); ++j) {
        if (edges[i][j] == p1 || edges[i][j] == p2) return edges[i][j];
      }
    }
    return p1;
  }
};
