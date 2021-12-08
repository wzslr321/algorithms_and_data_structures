bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
  queue<int> nodes;
  unordered_map<int, bool> visited;
  nodes.push(start);
  while (nodes.size() > 0) {
    auto curr = nodes.front();
    nodes.pop();
    if (visited[curr] == true) continue;
    if (curr == end) return true;
    visited[curr] = true;
    for (size_t i = 0; i < edges.size(); ++i) {
      if (edges[i][0] == curr) {
        nodes.push(edges[i][1]);
      }
      if (edges[i][1] == curr) {
        nodes.push(edges[i][0]);
      }
    }
  }
  return false;
}
