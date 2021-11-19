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
  int get_height(Node *node) { return node ? node->height : 0; }

  Node *dfs(Node *node, int value) {
    if (!node || node->value == value) return node;
    auto left = dfs(node->left, value);
    auto right = dfs(node->right, value);
    return !left ? right : left;
  }

  std::pair<Node *, Node *> find_max_in_subtree(Node *node) {
    if (!node) return std::pair<Node *, Node *>{nullptr, nullptr};
    while (node->right) {
      node = node->right;
    }
    return std::pair<Node *, Node *>{node, node->parent};
  }

  Node *search_parent(Node *node, int value) {
    if (!node) return node;
    auto tmp = node;
    auto direction = node->value > value ? node->left : node->right;
    node = search_parent(direction, value);
    if (!node) return tmp;
    return node;
  }

  void rotate(Node *node, Node *&subtree_child) {
    if (node->parent) {
      if (subtree_child == node->left)
        node->parent->left = subtree_child;
      else
        node->parent->right = subtree_child;

      node->parent->height -= 1;
    }
    subtree_child->parent = node->parent;
    node->parent = subtree_child;
    Node *subtree = nullptr;
    if (subtree_child == node->left)
      subtree = subtree_child->right;
    else
      subtree = subtree_child->left;

    if (subtree) subtree->parent = node;

    subtree_child == node->left ? subtree_child->right = node
                                : subtree_child->left = node;
    subtree_child->height = node->height;
    subtree_child == node->left ? subtree_child = nullptr
                                : subtree_child = subtree;
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

    if (left_height > right_height + 1) rotate(node, node->left);
    if (right_height > left_height + 1) rotate(node, node->right);

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
    const auto &max_node_pair = find_max_in_subtree(node->left);
    if (!max_node_pair.first) {
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
    const auto &child = max_node_pair.first;
    const auto &parent = max_node_pair.second;
    node->value = child->value;
    if (child == parent->left) {
      parent->left = child->left;
    } else {
      if (!parent->left) parent->height -= 1;
      parent->right = child->left;
    }
    update(parent);
  }
};

void scan(Node *node);

auto main() -> int {
  avl_tree tree{};
  tree.insert(5);
  tree.insert(4);
  tree.insert(3);
  /*
  tree.insert(2);
  tree.insert(1);
  tree.insert(6);
  tree.insert(10);
  tree.insert(15);
  tree.insert(16);
  tree.insert(19);
  tree.insert(21);
  */
  scan(tree.get_root());
  std::cout << "\nHeight: " << tree.get_height(tree.get_root()) << '\n';

  // std::cout << "\n\n";
  // scan(tree.get_root());

  // std::cout << "\nHeight: " << tree.get_height(tree.get_root()) << '\n';

  return 0;
}

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

void scan(Node *node) {
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
