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
  int height;

 public:
  red_black_tree() {
    root = nullptr;
    height = 0;
  }

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

  void rotate(Node *node) {
    if (!node) return;
    if (!node->parent) return;
    auto grandparent = node->parent->parent;
    node->parent->parent = node;
    if (node == node->parent->right) {
      node->parent->right = node->left;
      if (node->left) node->left->parent = node->parent;
      node->left = node->parent;
      node->left->color = 'r';
    } else {
      node->parent->left = node->right;
      if (node->right) node->right->parent = node->parent;
      node->right = node->parent;
      node->right->color = 'r';
      node->color = 'b';
      node->parent->parent = node;
    }
    if (grandparent) {
      if (node->parent == grandparent->left)
        grandparent->left = node;
      else
        grandparent->right = node;

      node->parent = grandparent;
    } else {
      node->color = 'b';
      node->parent = nullptr;
      root = node;
    }

    if (node->color == 'r' && node->left && node->left->color == 'r') {
      return rotate(node);
    }
    if (node->color == 'r' && node->right && node->right->color == 'r') {
      return rotate(node);
    }
  }

  void push_blackness(Node *node) {
    node->left->color = 'b';
    node->right->color = 'b';
    if (node != root) node->color = 'r';
  }

  bool is_grandparent_rotatable(Node *node) {
    if (!node || node->color != 'r') return false;
    if (node->parent && node->parent->color == 'r') return true;
    return false;
  }

  void insert(int value) {
    auto node = new Node(value);
    if (!root) {
      node->color = 'b';
      root = node;
      return;
    }
    const auto &parent = find_parent(root, value);
    if (!parent) return;
    node->parent = parent;

    if (node->value > parent->value)
      parent->right = node;
    else
      parent->left = node;

    auto grandparent = parent->parent;
    if (parent->color == 'r') {
      bool can_push_blackness = is_uncle_red(grandparent);
      if (can_push_blackness) {
        push_blackness(grandparent);
        bool canRotate = is_grandparent_rotatable(grandparent);
        if (canRotate) rotate(grandparent);
      } else {
        rotate(parent);
      }
    }
  }
};

void display(const Node *node);

auto main() -> int {
  red_black_tree tree{};

  tree.insert(26);
  tree.insert(41);
  tree.insert(47);
  tree.insert(30);
  tree.insert(17);
  tree.insert(14);
  tree.insert(28);
  tree.insert(38);
  tree.insert(35);
  tree.insert(10);

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
