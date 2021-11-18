#include <iostream>

template <typename T> struct Node {
  T value;
  Node<T> *left = nullptr;
  Node<T> *right = nullptr;
  Node<T> *parent = nullptr;
  int height = 1;
};

template <typename T> struct avl_tree {
 private:
  Node<T> *root;
  int height;

 public:
  avl_tree() {
    root = nullptr;
    height = 0;
  }

  Node<T> *get_root() { return root; }
  int get_height(Node<T> *node) { return node->height; }

  void print_node(Node<T> *node) {
    std::cout << "Value: " << node->value << '\t';
    std::cout << "Left Child: ";
    if (node->left != nullptr) {
      std::cout << node->left->value << '\t';
    } else {
      std::cout << node->left << '\t';
    }
    std::cout << "Right child: ";
    if (node->right != nullptr) {
      std::cout << node->right->value << '\t';
    } else {
      std::cout << node->right << '\t';
    }
    std::cout << "Parent: ";
    if (node->parent != nullptr) {
      std::cout << node->parent->value << '\t';
    } else {
      std::cout << node->parent << '\t';
    }
    std::cout << "Height: " << node->height << '\n';
  }

  void dfs(Node<T> *node) {
    print_node(node);
    if (node->left != nullptr) {
      dfs(node->left);
    }
    if (node->right != nullptr) {
      dfs(node->right);
    }
  }

  Node<T> *dfs(Node<T> *node, T value) {
    if (node == nullptr)
      return node;
    if (node->value > value) {
      auto tmp = node;
      node = dfs(node->left, value);
      if (node == nullptr)
        return tmp;
    } else {
      auto tmp = node;
      node = dfs(node->right, value);
      if (node == nullptr)
        return tmp;
    }
    return node;
  }

  void ufs(Node<T> *node) {
    ++node->height;
    if (node->parent != nullptr) {
      if (node->parent->height == node->height) {
        if (node->right != nullptr) {
          // node->parent->right = node->right;
          // node->right->left = node;
          // node->parent = node->right;
        } else {
          auto tmp = node->parent->parent;
          node->right = node->parent;
          node->parent->parent = node;
          node->parent = tmp;
          node->right->height -= 1;
          node->right->left = nullptr;
          if (tmp == nullptr)
            root = node;
        }
      }
      node = node->parent;
      // ufs(node);
    }
  }

  void insert(T value) {
    auto node = new Node<T>{};
    node->value = value;
    if (root == nullptr) {
      root = node;
      return;
    }
    const auto &parent = dfs(root, value);
    if (parent == nullptr)
      return;
    node->parent = parent;
    if (parent->value > node->value) {
      parent->left = node;
      if (parent->right == nullptr)
        ufs(parent);
    } else {
      parent->right = node;
      if (parent->left == nullptr)
        ufs(parent);
    }
  }
};

auto main() -> int {
  avl_tree<int> tree{};
  tree.insert(5);
  tree.insert(4);
  tree.insert(3);

  const auto root = tree.get_root();
  tree.dfs(root);
  std::cout << "\nHeight: " << tree.get_height(root) << '\n';

  return 0;
}
