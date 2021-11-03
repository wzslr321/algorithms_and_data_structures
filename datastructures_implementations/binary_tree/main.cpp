#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    Node* parent;
};

template <typename T>
class binary_tree {
   private:
    Node<T>* root;
    T height;

   public:
    binary_tree() { root = NULL; }

    void insert(T value) {
        auto node = new Node<T>;
        node->data = value;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        if (root == NULL) {
            root = node;
            height = 0;
        } else {
            auto tmp = root;
            while (tmp->right != node && tmp->left != node) {
                if (node->data == tmp->data) break;
                if (node->data > tmp->data) {
                    if (tmp->right == NULL) {
                        tmp->right = node;
                        node->parent = tmp;
                        if (node->parent->left == NULL) ++height;
                    } else {
                        tmp = tmp->right;
                    }
                } else {
                    if (tmp->left == NULL) {
                        tmp->left = node;
                        node->parent = tmp;
                        if (node->parent->right == NULL) ++height;
                    } else {
                        tmp = tmp->left;
                    }
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
                        if (previous->left == NULL) --height;
                    }
                }
                if (previous->left != NULL) {
                    if (previous->left->data == value) {
                        previous->left = NULL;
                        delete tmp;
                        if (previous->right == NULL) --height;
                    }
                }
                if (root->data == value) {
                    root = tmp->right;
                    root->left = tmp->left;
                    delete tmp;
                    --height;
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

    bool search(T value) {
        auto tmp = root;
        while (true) {
            if (tmp->data == value) return true;
            if (value > tmp->data) {
                if (tmp->right == NULL)
                    return false;
                else
                    tmp = tmp->right;
            } else {
                if (tmp->left == NULL)
                    return false;
                else
                    tmp = tmp->left;
            }
        }
    }

    bool search_recursively(Node<T>* current_root, T value) {
        if (current_root == NULL) return false;
        if (current_root->data == value) return true;
        auto left = search_recursively(current_root->left, value);
        auto right = search_recursively(current_root->right, value);
        // it can be one liner, it looks ugly though so I did it this way here
        return left || right;
    }

    void dfs() {
        auto node{root};
        stack<Node<T>*> st;
        st.push(node);
        while (st.size() > 0) {
            auto current{st.top()};
            st.pop();
            if (current->right != NULL) st.push(current->right);
            if (current->left != NULL) st.push(current->left);
            cout << current->data << ' ';
        }
    }

    void bfs() {
        auto node{root};
        queue<Node<T>*> qq;
        qq.push(node);
        while (qq.size() > 0) {
            auto current{qq.front()};
            qq.pop();
            if (current->left != NULL) qq.push(current->left);
            if (current->right != NULL) qq.push(current->right);
            cout << current->data << ' ';
        }
    }

    T sum_recursively(Node<T>* current_root) {
        if (current_root == NULL) return 0;
        auto left_subtree = sum_recursively(current_root->left);
        auto right_subtree = sum_recursively(current_root->right);
        return current_root->data + left_subtree + right_subtree;
    }

    T max_root_to_leaf_sum(Node<T>* current_root) {
        if (current_root == NULL) return INT_MIN;
        if (current_root->left == NULL && current_root->right == NULL)
            return current_root->data;

        auto max_left = INT_MIN;
        auto max_right = INT_MIN;
        max_left = max_root_to_leaf_sum(current_root->left);
        max_right = max_root_to_leaf_sum(current_root->right);
        auto max_subtree = max(max_left, max_right);
        return current_root->data + max_subtree;
    }

    Node<T>* get_root() { return root; }

    /*
    T get_height(Node<T>* current_root) {
        if (current_root == NULL) return 0;
        if (current_root->left == NULL && current_root->right == NULL) return 1;
        auto max_left = INT_MIN;
        auto max_right = INT_MIN;
        max_left = get_height(current_root->left);
        max_right = get_height(current_root->right);
        return 1 + max(max_left, max_right);
    }
    */

    T get_height() {
        return height;
    }
};

auto main() -> int {
    binary_tree<int> tree;
    tree.insert(20);
    tree.insert(15);
    tree.insert(30);
    tree.insert(10);
    tree.insert(18);
    tree.insert(7);
    tree.dfs();
    cout << '\n';
    tree.bfs();
    cout << '\n';
    cout << tree.search(7) << '\t';
    cout << tree.search_recursively(tree.get_root(), 3) << '\n';
    cout << tree.sum_recursively(tree.get_root()) << '\n';
    cout << tree.max_root_to_leaf_sum(tree.get_root()) << '\n';
    // cout << tree.get_height(tree.get_root()) << '\n';
    cout << tree.get_height() << '\n';

    return 0;
}
