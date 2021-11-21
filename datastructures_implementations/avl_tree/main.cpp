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

  const Node *get_root() { return root; }

  int get_height(const Node *node) { return node ? node->height : 0; }

  Node *dfs(Node *node, int value) {
    if (!node || node->value == value) return node;
    auto left = dfs(node->left, value);
    auto right = dfs(node->right, value);
    return !left ? right : left;
  }

  Node *find_max_in_subtree(Node *node) {
    if (!node) return nullptr;
    while (node->right) {
      node = node->right;
    }
    return node;
  }

  Node *search_parent(Node *node, int value) {
    if (!node) return node;
    auto tmp = node;
    auto direction = node->value > value ? node->left : node->right;
    node = search_parent(direction, value);
    if (!node) return tmp;
    return node;
  }

  void rotate_right(Node *node) {
    if (node->parent) {
      node->parent->left = node->left;
      node->parent->height -= 1;
    }
    node->left->parent = node->parent;
    node->parent = node->left;
    auto subtree = node->left->right;
    if (subtree) subtree->parent = node;
    node->left->right = node;
    node->left->height = node->height;
    node->left = subtree;
    if (node->left) {
      if (node->right) {
        node->height = std::max(node->left->height, node->right->height) + 1;
      } else {
        node->height = node->left->height + 1;
      }
    } else {
      if (node->right) {
        node->height = node->right->height + 1;
      } else {
        node->height -= 2;
      }
    }
  }

  void rotate_left(Node *node) {
    if (node->parent) {
      node->parent->right = node->right;
      node->parent->height -= 1;
    }
    node->right->parent = node->parent;
    node->parent = node->right;
    auto subtree = node->right->left;
    if (subtree) subtree->parent = node;
    node->right->left = node;
    node->right->height = node->height;
    node->right = subtree;
    if (node->left) {
      if (node->right) {
        node->height = std::max(node->left->height, node->right->height) + 1;
      } else {
        node->height = node->left->height + 1;
      }
    } else {
      if (node->right) {
        node->height = node->right->height + 1;
      } else {
        node->height -= 2;
      }
    }
  }

  void update(Node *node, bool insert = false) {
    if (!node) return;
    auto left_height = node->left ? node->left->height : 0;
    auto right_height = node->right ? node->right->height : 0;

    node->height = std::max(left_height, right_height) + 1;

    if (left_height > right_height + 1) rotate_right(node);
    if (right_height > left_height + 1) rotate_left(node);

    if (!node->parent) root = node;

    update(node->parent, insert);
  }

  void insert(int value) {
    auto node = new Node{};
    node->value = value;
    if (!root) {
      root = node;
      return;
    }
    const auto &parent = search_parent(root, value);
    if (!parent) return;
    node->parent = parent;
    parent->value > node->value ? parent->left = node : parent->right = node;
    update(parent, true);
  }

  void delete_leaf(Node *node) {
    if (!node->parent) {
      root = nullptr;
      if (!node->left && !node->right) {
        delete node;
        return;
      }
    }
    if (node == node->parent->left) {
      if (!node->parent->right) node->parent->height -= 1;
      node->parent->left = nullptr;
    } else {
      if (!node->parent->left) node->parent->height -= 1;
      node->parent->right = nullptr;
    }

    update(node->parent);

    node->parent = nullptr;
    delete node;
  }

  void remove(int value) {
    const auto &node = dfs(root, value);
    if (!node) return;
    const auto &max_node = find_max_in_subtree(node->left);
    if (!max_node) {
      if (node->right) {
        node->value = node->right->value;
        node->right->parent = nullptr;
        node->right = nullptr;
        node->height -= 1;
        delete node->right;
      } else {
        delete_leaf(node);
      }
      return;
    }
    node->value = max_node->value;
    if (max_node == max_node->parent->left) {
      max_node->parent->left = max_node->left;
    } else {
      if (!max_node->parent->left) max_node->parent->height -= 1;
      max_node->parent->right = max_node->left;
      if (max_node->left) max_node->left->parent = node->left;
    }
    update(max_node->parent);
  }
};

void scan(const Node *node);

auto main() -> int {
  avl_tree tree{};
  for (auto i = 1; i < 49; ++i) {
    tree.insert(i);
  }

  scan(tree.get_root());
  std::cout << "\nHeight: " << tree.get_height(tree.get_root()) << '\n';

  tree.remove(24);
  tree.remove(40);
  tree.remove(39);
  tree.remove(38);
  tree.remove(37);
  tree.remove(44);
  tree.remove(43);
  tree.remove(42);
  tree.remove(41);
  tree.remove(36);
  tree.remove(35);

  std::cout << "\n\n";
  scan(tree.get_root());

  std::cout << "\nHeight: " << tree.get_height(tree.get_root()) << '\n';

  return 0;
}

// Niżej jest tylko wyświetlanie

void print_node(const Node *node) {
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

void scan(const Node *node) {
  if (!node) {
    std::cout << "Tree is empty\n";
    return;
  }
  print_node(node);
  if (node->left) {
    scan(node->left);
  }
  if (node->right) {
    scan(node->right);
  }
}
