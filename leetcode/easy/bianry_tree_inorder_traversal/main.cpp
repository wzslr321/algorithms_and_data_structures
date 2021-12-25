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

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> res{};
  const auto &tmp = root->left;
  const auto &tmp2 = root->right;
  while (tmp->left) {
    res.push_back(tmp->left->val);
    tmp = tmp->left;
  }
  if (root) {
    res.push_back(root->val);
  }
  while (tmp->right) {
    res.push_back(tmp->right->val);
    tmp = tmp->right;
  }
  return res;
}

int main() { 

    return 0; 
}
