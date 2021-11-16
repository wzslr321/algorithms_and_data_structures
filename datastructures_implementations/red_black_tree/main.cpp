#include <cstdlib>
#include <iostream>

template <typename T> struct Node {
  bool color = 0; // black
  T key;
  Node<T> *parent = nullptr;
  Node<T> *left = nullptr;
  Node<T> *right = nullptr;
};

template <typename T> class red_black_tree {
 private:
  Node<T> *root;
  int height;

 public:
  red_black_tree() {
    root = nullptr;
    height = 0;
  }

  void insert(T value) {
    auto node = new Node<T>;
    node->key = value;
    if (root == nullptr) {
      root = node;
      return;
    }
    
  }
};

auto main() -> int { return 0; }
