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
            auto tmp = root;
            while (tmp->right != node && tmp->left != node) {
                if (node->data == tmp->data) break;
                if (node->data > tmp->data) {
                    if (tmp->right == NULL)
                        tmp->right = node;
                    else
                        tmp = tmp->right;
                } else {
                    if (tmp->left == NULL)
                        tmp->left = node;
                    else
                        tmp = tmp->left;
                }
            }
        }
    }

    void remove(T value) {
        auto tmp = root;
        auto previous = new Node<T>;
        while (true) {
            if (tmp->data == value) {
                if (previous->right != NULL) {
                    if (previous->right->data == value) {
                        previous->right = NULL;
                        delete tmp;
                    }
                }
                if (previous->left != NULL) {
                    if (previous->left->data == value) {
                        previous->left = NULL;
                        delete tmp;
                    }
                }
                if (root->data == value) {
                    root = tmp->right;
                    root->left = tmp->left;
                    delete tmp;
                }
                break;
            }
            if (tmp->data < value) {
                if (tmp->right == NULL) break;
                previous = tmp;
                tmp = tmp->right;
            }
            if (tmp->data > value) {
                if (tmp->left == NULL) break;
                previous = tmp;
                tmp = tmp->left;
            }
        }
    }

    void display() { cout << root->right->right; }
};

auto main() -> int {
    binary_tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(8);
    tree.insert(9);
    tree.remove(9);
    tree.display();

    return 0;
}
