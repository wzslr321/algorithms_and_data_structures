using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int tilt = 0;

  int sum(TreeNode *root) {
    if (root == nullptr) return 0;
    auto left = sum(root->left);
    auto right = sum(root->right);
    tilt += abs(left - right);
    return root->val + left + right;
  }

  int findTilt(TreeNode *root) {
    sum(root);
    return tilt;
  }
};
