#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void solve(TreeNode *root, vector<int> &res) {
  if (root) {
    solve(root->left, res);
    res.push_back(root->val);
    solve(root->right, res);
  }
}

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> res{};
  solve(root, res);
  return res;
}

int main() { return 0; }
