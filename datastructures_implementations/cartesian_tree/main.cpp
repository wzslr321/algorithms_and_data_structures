#include <cstdlib>
#include <iostream>
#include <vector>

struct Node {
  int key, prior;
  Node *left, *right;

  Node() : key(0), prior(0), left(nullptr), right(nullptr) {}
  explicit Node(int val)
      : key(val), prior(rand()), left(nullptr), right(nullptr) {}
};

struct cartesian_tree {
 private:
  Node *root;
  Node *last;

 public:
  cartesian_tree() {
    root = nullptr;
    last = nullptr;
  }

  auto get_root() -> Node * { return root; }

  auto split(Node *node, int key, Node *&left, Node *&right) -> void {
    if (!node)
      left = right = nullptr;
    else if (node->key <= key)
      split(node->right, key, node->right, right), left = node;
    else
      split(node->left, key, left, node->left), right = node;
  }

  auto insert(Node *&rnode, Node *node) -> void {
    if (!rnode)
      rnode = node;
    else if (node->prior > rnode->prior)
      split(rnode, node->key, node->left, node->right), rnode = node;
    else
      insert(rnode->key <= node->key ? rnode->right : rnode->left, node);
  }

  auto inorder_traversal(Node *node) -> void {
    if (!node) return;
    inorder_traversal(node->left);
    std::cout << node->key << ' ';
    inorder_traversal(node->right);
  }
};

auto main() -> int {

  cartesian_tree tree;

  return EXIT_SUCCESS;
}
