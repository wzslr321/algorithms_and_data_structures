#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T> struct Node {
  T data;
  Node<T> *parent;
  std::vector<Node<T> *> children;
  Node<T> *sibling;
  Node() : data(0), parent(nullptr), children({}), sibling(nullptr) {}
  explicit Node(T data)
      : data(data), parent(nullptr), children({}), sibling(nullptr) {}
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

  const int get_height() { return height; }
  const Node<T> *get_root() { return root; }

  void insert_root(Node<T> *&node) { root = node; }

  void dfs(const Node<T> *node) {
    for (const auto &n : node->children) {
      dfs(n);
    }
  }

  Node<T> *dfs(Node<T> *node, const T value) {
    if (node == nullptr || node->data == value) return node;

    for (const auto &n : node->children) {
      auto result = dfs(n, value);
      if (result && result->data == value) return result;
    }

    return nullptr;
  }

  void insert_to(const T top, const T value) {
    auto node = new Node<T>(value);
    if (!root) return insert_root(node);

    auto parent = dfs(root, top);
    if (!parent) return;
    node->parent = parent;

    auto &children = parent->children;
    if (!children.empty()) children.back()->sibling = node;
    children.push_back(node);
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
