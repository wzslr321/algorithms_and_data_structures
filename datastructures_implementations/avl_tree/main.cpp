#include <iostream>

template <typename T> struct Node {
  T value;
  Node<T> *left;
  Node<T> *right;
};

template <typename T> struct avl_tree {
 private:
  Node<T> *root;

 public:
  avl_tree() { root = nullptr; }

  Node<T> *get_root() { return root; }

  void dfs(Node<T> *node) {
    std::cout << "DFS: " << node->value << ' ';
    if (node->left != nullptr)
      dfs(node->left);
    else if (node->right != nullptr)
      dfs(node->right);
    std::cout << '\n';
  }

  Node<T> *dfs(Node<T> *node, T value) {
    if (value > node->value) {
      if (node->right != nullptr)
        dfs(node->right, value);
      else
        return node;
    } else {
      if (node->left != nullptr)
        dfs(node->left, value);
      else
        return node;
    }
    return nullptr;
  }

  void insert(T value) {
    auto node = new Node<T>;
    node->value = value;
    node->right = nullptr;
    node->left = nullptr;
    if (root == nullptr) {
      root = node;
      return;
    }
    const auto &parent = dfs(root, value);
    if (parent == nullptr) return;
    if (parent->value > node->value)
      parent->left = node;
    else
      parent->right = node;
  }
};

auto main() -> int {
  avl_tree<int> tree{};
  tree.insert(5);
  tree.insert(7);
  tree.dfs(tree.get_root());

  return 0;
}
