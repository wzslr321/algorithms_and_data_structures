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

    void insert(T value) {
        auto node = new Node<T>;
        node->value = value;
        node->left = NULL;
        node->left = NULL;
        if (root == NULL) {
            root = node;
        } else {
            auto tmp = root;
            ;
        }
    }
};

auto main() -> int {
    avl_tree<int> tree;
    tree.insert(5);

    return 0;
}
