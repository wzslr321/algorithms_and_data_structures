#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T> struct Node {
  T data;
  Node<T> *parent;
  std::vector<Node<T> *> children;
  Node<T> *sibling;
};

template <typename T> class rooted_tree {
 private:
  Node<T> *root;
  int height;

 public:
  rooted_tree() {
    root = nullptr;
    height = 0;
  }

  const int &get_height() { return height; }
  const Node<T> *get_root() { return root; }

  void insert_root(Node<T> *&node) { root = node; }

  Node<T> *create_node(const T value) {
    auto node = new Node<T>;
    node->data = value;
    node->parent = nullptr;
    node->children = {};
    node->sibling = nullptr;

    return node;
  }

  void dfs(const Node<T> *node) {
    print_node(node);
    for (const auto &n : node->children) {
      dfs(n);
    }
  }

  Node<T> *dfs(Node<T> *node, const T value) {
    if (node == nullptr || node->data == value)
      return node;

    for (const auto &n : node->children) {
      auto result = dfs(n, value);
      if (result != nullptr && result->data == value)
        return result;
    }

    return nullptr;
  }

  void insert_to(const T top, const T value) {
    auto node = create_node(value);
    if (root == nullptr)
      return insert_root(node);

    auto parent = dfs(root, top);
    if (parent == nullptr)
      return;
    node->parent = parent;

    auto &children = parent->children;
    if (!children.empty())
      children.back()->sibling = node;
    children.push_back(node);
  }

  void print_node(const Node<T> *node) {

    std::cout << "Value : " << node->data << "\tparent: ";
    if (node->parent == nullptr) {
      std::cout << node->parent;
    } else {
      std::cout << node->parent->data;
    }
    if (node->sibling != nullptr) {
      std::cout << "\tsibling: " << node->sibling->data;
    } else {
      std::cout << "\tsibling: " << node->sibling;
    }
    std::cout << "\tchildren: ";
    for (const auto &n : node->children) {
      std::cout << n->data << ' ';
    }
    std::cout << '\n';
  }
};

auto main() -> int {
  auto tree = rooted_tree<int>{};

  tree.insert_to(0, 1);
  tree.insert_to(1, 2);
  tree.insert_to(1, 3);
  tree.insert_to(1, 4);
  tree.insert_to(2, 5);
  tree.insert_to(2, 6);
  tree.insert_to(3, 7);
  tree.insert_to(3, 8);
  tree.insert_to(3, 9);
  tree.insert_to(3, 10);
  tree.insert_to(4, 11);
  tree.insert_to(6, 12);
  tree.insert_to(9, 13);
  tree.insert_to(9, 14);

  const auto root = tree.get_root();

  tree.dfs(root);

  return EXIT_SUCCESS;
}
