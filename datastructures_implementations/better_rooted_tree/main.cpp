#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T> struct Node {
  T data;
  Node<T> *parent;
  std::vector<Node<T> *> neighbours;
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
    node->neighbours = {};

    return node;
  }

  Node<T> *search(Node<T> *s_root, const T value) {
    if (s_root == nullptr)
      return nullptr;
    if (s_root->data == value)
      return s_root;

    for (const auto &n : s_root->neighbours) {
      auto result = search(n, value);
      if (result->data == value)
        return result;
    }

    return nullptr;
  }

  void insert_to(const T top, const T value) {
    auto node = create_node(value);
    if (root == nullptr)
      return insert_root(node);

    auto parent = search(root, top);
    if (parent == nullptr) {
      std::cout << "There is no such a node\n";
      return;
    }

    auto nb = parent->neighbours;
    nb.push_back(node);
  }
};

auto main() -> int {
  auto tree = rooted_tree<int>{};

  tree.insert_to(12, 5);
  tree.insert_to(5, 13);
  tree.insert_to(6, 10);

  return EXIT_SUCCESS;
}
