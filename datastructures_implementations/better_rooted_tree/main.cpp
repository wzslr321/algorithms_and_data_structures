#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T> struct Node {
  T data;
  Node<T> *parent;
  std::vector<Node<T> *> *neighbours;
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
    node->neighbours = nullptr;

    std::cout << "Node value: " << node->data << '\n';

    return node;
  }

  void dfs(Node<T> *node, Node<T> *parent, const T wanted = 0) {

    std::cout << node->data;
    if (node->data == wanted)
      std::cout << "FOUND!!!\n";
    node->parent = parent;
    for (const auto &n : *node->neighbours) {
      if (n != node->parent) {
        dfs(n, node);
      }
    }
  }

  void insert_to(const T top, const T value) {
    auto node = create_node(value);
    if (root == nullptr)
      return insert_root(node);

    dfs(root, nullptr, top);
  }
};

auto main() -> int {
  auto tree = rooted_tree<int>{};

  tree.insert_to(12, 5);
  tree.insert_to(5, 13);
  tree.insert_to(6, 10);

  return EXIT_SUCCESS;
}
