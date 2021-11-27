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

  void rotate_left(Node *node) {
    auto parent = node->parent;

    parent->color = 'r';
    parent->right = node->left;
    node->left = parent;

    if (parent->parent) {
      node->parent = parent->parent;

      if (node->parent->value > parent->value)
        parent->parent->left = node;
      else
        parent->parent->right = node;

    } else {
      node->color = 'b';
      node->parent = nullptr;
      root = node;
    }

    parent->parent = node;
    if (node->left) node->left->parent = parent;
  }

  void rotate_right(Node *node) {}

  void push_blackness(Node *node) {
    node->left->color = 'b';
    node->right->color = 'b';
    if (node != root) node->color = 'r';
  }

  bool is_grandparent_rotatable(Node *node) {
    if (!node || node->color != 'r') return false;
    const auto &grandparent = node->parent->parent;
    if (node->parent && is_uncle_red(grandparent)) {
      push_blackness(grandparent);
      return false;
    }
    if (node->parent && node->parent->color == 'r') return true;
    return false;
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
    // Inserted node and it's parent are red - actions are needed.
    if (parent->color == 'r') {
      // Grandparent can't be null here

      // If uncle of inserted node is also red, push_blackness is enough
      if (is_uncle_red(grandparent)) return push_blackness(grandparent);

      // Otherwise, rotation is needed.

      // Node and Parent are both right childs --> rotate left -- 1st scenario
      if (parent->right == node && grandparent->right == parent)
        return rotate_left(parent);
    }
  }
};

void display(const Node *node);

auto main() -> int {
  red_black_tree tree{};

  tree.insert(25);
  tree.insert(50);
  tree.insert(75);
  /*
  tree.insert(30);
  tree.insert(17);
  tree.insert(14);
  tree.insert(28);
  tree.insert(38);
  tree.insert(35);
  tree.insert(10);
  tree.insert(30);
  tree.insert(20);
  tree.insert(29);
  tree.insert(18);
  */

  display(tree.get_root());

  return 0;
}

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
  std::cout << "Color: " << (node->color == 'r' ? "red" : "black") << '\n';
}

void display(const Node *node) {
  if (!node) {
    std::cout << "Tree is empty\n";
    return;
  }
  print_node(node);
  if (node->left) {
    display(node->left);
  }
  if (node->right) {
    display(node->right);
  }
}
