#include <cstdlib>
#include <iostream>

struct Node {
  char color;
  int value;
  Node *parent;
  Node *left;
  Node *right;

  explicit Node(int x)
      : color('r'), value(x), parent(nullptr), left(nullptr), right(nullptr) {}
};

class red_black_tree {
 private:
  Node *root;

 public:
  red_black_tree() { root = nullptr; }

  const Node *get_root() { return root; }

  Node *find_node(Node *node, int value) {
    if (!node) return node;
    if (node->value == value) return node;
    auto direction = node->value > value ? node->left : node->right;
    node = find_node(direction, value);
    return node;
  }

  Node *find_parent(Node *node, int value) {
    if (!node) return node;
    auto tmp = node;
    auto direction = node->value > value ? node->left : node->right;
    node = find_parent(direction, value);
    if (!node) return tmp;
    return node;
  }

  bool is_uncle_red(Node *node) {
    if (!node) return false;

    bool is_left_red = node->left && node->left->color == 'r';
    bool is_right_red = node->right && node->right->color == 'r';

    if (is_left_red && is_right_red) return true;
    return false;
  }

  void check_rotation(Node *node) {
    auto grandparent = node->parent->parent;

    if (node == node->parent->left && grandparent->right == node->parent)
      return single_rotate_right(node->parent);
    if (node == node->parent->right && grandparent->left == node->parent)
      return single_rotate_left(node->parent);
    if (node == node->parent->right && grandparent->right == node->parent)
      return rotate_left(node->parent);
    if (node == node->parent->left && grandparent->left == node->parent)
      return rotate_right(node->parent);
  }

  void update_on_rotation(Node *node, Node *grandparent) {
    node->color = 'b';
    node->parent->color = 'r';

    if (grandparent) {
      node->parent = grandparent;

      if (grandparent->value > node->parent->value)
        grandparent->left = node;
      else
        grandparent->right = node;

    } else {
      node->parent = nullptr;
      root = node;
    }

    grandparent = node;
  }

  void rotate_left(Node *node) {
    auto parent = node->parent;

    parent->right = node->left;
    if (node->left) node->left->parent = parent;
    node->left = parent;

    update_on_rotation(node, parent->parent);
  }

  void rotate_right(Node *node) {
    auto parent = node->parent;

    parent->left = node->right;
    if (node->right) node->right->parent = parent;
    node->right = parent;

    update_on_rotation(node, parent->parent);
  }

  void single_rotate_left(Node *node) {
    auto parent = node->parent;
    auto tmp = node->right->left;
    node->parent = node->right;
    parent->left = node->right;
    node->right->parent = parent;
    node->right->left = node;
    if (tmp) tmp->parent = node;
    node->right = tmp;
    rotate_right(node->parent);
  }

  void single_rotate_right(Node *node) {
    auto parent = node->parent;
    auto tmp = node->left->right;
    node->parent = node->left;
    parent->right = node->left;
    node->left->parent = parent;
    node->left->right = node;
    if (tmp) tmp->parent = node;
    node->left = tmp;
    rotate_left(node->parent);
  }

  void push_blackness(Node *node) {
    node->left->color = 'b';
    node->right->color = 'b';
    if (node == root) return;
    node->color = 'r';

    auto grandparent = node->parent->parent;
    if (node->parent->color != 'r') return;
    if (!grandparent) return;

    if (is_uncle_red(grandparent)) return push_blackness(grandparent);

    check_rotation(node);
  }

  void insert_root(Node *node) {
    node->color = 'b';
    root = node;
  }

  void insert_to_parent(Node *node, Node *parent) {
    node->parent = parent;
    if (node->value > parent->value)
      parent->right = node;
    else
      parent->left = node;
  }

  void insert(int value) {
    auto node = new Node(value);
    if (!root) return insert_root(node);

    const auto &parent = find_parent(root, value);
    if (!parent) return;
    insert_to_parent(node, parent);

    auto grandparent = parent->parent;

    if (parent->color == 'r') {

      if (is_uncle_red(grandparent)) return push_blackness(grandparent);

      check_rotation(node);
    }
  }

  // needs to be implemented
  void remove(int value) {
    auto node = find_node(root, value);
    if (!node) return;
    std::cout << node->value << '\n';
  }
};

auto main() -> int {
  red_black_tree tree{};

  for (int i = 1; i <= 10; ++i) {
    tree.insert(i);
  }

  return 0;
}
