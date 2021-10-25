#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
};

template <typename T>
class binary_tree {
   private:
    Node<T>* root;

   public:
    binary_tree() { root = NULL; }

    void insert(T value) {
        auto node = new Node<T>;
        node->data = value;
        node->left = NULL;
        node->right = NULL;
        if (root == NULL) {
            root = node;
        } else {
            Node<T>* tmp = root;
            auto found{false};
            while (!found) {
                if (node->data > tmp->data) {
                    if (tmp->right == NULL) {
                        tmp->right = node;
                        found = true;
                        break;
                    }
                    tmp = tmp->right;
                }
                if (node->data < tmp->data) {
                    if (tmp->left == NULL) {
                        tmp->left = node;
                        found = true;
                        break;
                    }
                    tmp = tmp->left;
                }
            }
        }
    }

    void display() {
        cout << root->right->right->data;
    }
};

auto main() -> int {
    binary_tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(8);
    tree.insert(9);
    tree.display();

    return 0;
}
