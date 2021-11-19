#include <iostream>

struct Node {
  int value;
  Node *left = nullptr;
  Node *right = nullptr;
  Node *parent = nullptr;
  int height = 1;
};

struct avl_tree {
 private:
  Node *root;
  int height;

 public:
  avl_tree() {
    root = nullptr;
    height = 0;
  }

  Node *get_root() { return root; }
  int get_height(Node *node) { return node->height; }

  void print_node(Node *node) {
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

  void dfs(Node *node) {
    print_node(node);
    if (node->left != nullptr) {
      dfs(node->left);
    }
    if (node->right != nullptr) {
      dfs(node->right);
    }
  }

  Node *dfs(Node *node, int value) {
    if (node == nullptr || node->value == value)
      return node;
    auto left = dfs(node->left, value);
    auto right = dfs(node->right, value);
    return left == nullptr ? right : left;
  }

  Node *find_max_in_subtree(Node *node) {
    if (node == nullptr)
      return node;
    while (node->right != nullptr) {
      node = node->right;
    }
    return node;
  }

  Node *search_parent(Node *node, int value) {
    if (node == nullptr)
      return node;
    if (node->value > value) {
      auto tmp = node;
      node = search_parent(node->left, value);
      if (node == nullptr)
        return tmp;
    } else {
      auto tmp = node;
      node = search_parent(node->right, value);
      if (node == nullptr)
        return tmp;
    }
    return node;
  }

  void ufs(Node *node) {
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
      if (lsub != nullptr)
        lsub->parent = node;
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
      if (rsub != nullptr)
        rsub->parent = node;
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

  void insert(int value) {
    auto node = new Node{};
    node->value = value;
    if (root == nullptr) {
      root = node;
      return;
    }
    const auto &parent = search_parent(root, value);
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

  void remove(int value) {
    const auto &node = dfs(root, value);
    if (node == nullptr)
      return;
    const auto &max_node = find_max_in_subtree(node->left);
    if (max_node != nullptr) {
      node->value = max_node->value;
    } else {
      //
    }
    if (max_node == node->left)
      node->left = nullptr;
    if (max_node->parent > max_node)
      max_node->parent->left = nullptr;
    else
      max_node->parent->right = nullptr;
    max_node->parent = nullptr;
    max_node->left = nullptr;
    max_node->right = nullptr;
    delete max_node;
  }
};

auto main() -> int {
  avl_tree tree{};
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
  tree.insert(21);

  const auto root = tree.get_root();
  tree.dfs(root);
  std::cout << "\nHeight: " << tree.get_height(root) << '\n';

  tree.remove(19);
  tree.remove(15);
  tree.remove(10);

  std::cout << "\n\n";
  tree.dfs(root);

  std::cout << "\nHeight: " << tree.get_height(root) << '\n';

  return 0;
}
