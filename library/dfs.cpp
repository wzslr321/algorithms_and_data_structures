#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &graph, int start) {
  stack<int> st;
  st.push(start);
  int n = graph.size();
  vector<int> visited(n);
  visited[start] = 1;
  while (!st.empty()) {
    int curr = st.top();
    st.pop();
    for (const auto ngh : graph[curr])
      if (!visited[ngh]) st.push(ngh), visited[ngh] = 1;
  }
}

int main() {
    /*
     
    0
   / \
  1 - 2
 /     \
3       4

     */
  auto graph = vector<vector<int>>{
      {1, 2},   
      {0, 3, 4}, 
      {0, 4},   
      {1},       
      {1, 2}     
  };

  dfs(graph, 0);

  return 0;
}
