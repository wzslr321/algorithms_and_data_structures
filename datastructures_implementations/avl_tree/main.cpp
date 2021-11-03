#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
struct avl_tree {
   private:
    Node<T>* root;

   public:
    avl_tree() { root = NULL; }
};

auto main() -> int {
    avl_tree<int> tree;

    return 0;
}
