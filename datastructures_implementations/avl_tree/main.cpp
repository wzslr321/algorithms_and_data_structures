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
    if (node == nullptr)
      return;
    auto left_height = 0;
    auto right_height = 0;
    if (node->left != nullptr)
      left_height = node->left->height;
    if (node->right != nullptr)
      right_height = node->right->height;
    node->height = std::max(left_height, right_height) + 1;

    auto tmp = node->parent;
    if (left_height > right_height + 1) {
      if (node->parent != nullptr) {
        node->parent->left = node->left;
        node->parent->height -= 1;
      }
      node->parent = node->left;
      auto lsub = node->left->right;
      node->left->right = node;
      node->left->parent = tmp;
      node->left->height -= 1;
      node->left = lsub;
      node->left = nullptr;
      node->height -= 2;
    }
    if (right_height > left_height + 1) {
      if (node->parent != nullptr) {
        node->parent->right = node->right;
        node->parent->height -= 1;
      }
      node->parent = node->right;
      auto rsub = node->right->left;
      node->right->left = node;
      node->right->parent = tmp;
      node->right->height -= 1;
      node->right = node->right->left;
      node->right = rsub;
      node->height -= 2;
    }
    if (tmp == nullptr)
      root = node;
    node = node->parent;
    ufs(node);
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
    } else {
      parent->right = node;
    }
    ufs(parent);
  }
};

auto main() -> int {
  avl_tree<int> tree{};
  tree.insert(5);
  tree.insert(4);
  tree.insert(3);
  tree.insert(2);
  tree.insert(1);
  tree.insert(6);
  tree.insert(10);
  tree.insert(15);
  tree.insert(16);
  tree.insert(19);
  tree.insert(20);
  tree.insert(21);
  tree.insert(22);
  tree.insert(23);
  tree.insert(24);
  tree.insert(25);

  const auto root = tree.get_root();
  tree.dfs(root);
  std::cout << "\nHeight: " << tree.get_height(root) << '\n';

  return 0;
}
