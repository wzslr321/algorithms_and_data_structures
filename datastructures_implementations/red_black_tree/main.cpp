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
      root = node;
    }
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
    bool is_child_left = parent->value > node->value;
    is_child_left ? parent->left = node : parent->right = node;
    if (node->color == 'r' && parent->color == 'r') {
      bool is_parent_left = parent->parent->value > parent->value;
      if (!is_parent_left && !is_child_left) rotate_left(node->parent);
    }
  }
};

void display(const Node *node);

auto main() -> int {
  red_black_tree tree{};

  tree.insert(26);
  tree.insert(41);
  tree.insert(47);
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
