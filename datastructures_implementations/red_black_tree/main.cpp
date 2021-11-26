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

  void rotate_left(Node *node) {
    node->parent->right = nullptr;
    node->left = node->parent;
    node->left->parent = node;
    node->left->color = 'r';
    if (node->left == root) {
      node->color = 'b';
      node->parent = nullptr;
      root = node;
    }
  }

  bool is_uncle_red(Node *node) {
    if (!node) return false;

    bool is_left_red = node->left && node->left->color == 'r';
    bool is_right_red = node->right && node->right->color == 'r';

    if (is_left_red && is_right_red) return true;
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
        grandparent->left->color = 'b';
        grandparent->right->color = 'b';
        if (grandparent != root) grandparent->color = 'r';
        return;
      }

      rotate_left(parent);
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
  /*
  tree.insert(17);
  tree.insert(14);
  tree.insert(28);
  tree.insert(38);
  tree.insert(35);
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
