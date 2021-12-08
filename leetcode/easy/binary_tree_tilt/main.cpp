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
