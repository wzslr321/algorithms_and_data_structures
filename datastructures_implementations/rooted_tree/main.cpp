#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* top;
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
class rooted_tree {
   private:
    Node<T>* root;

   public:
    rooted_tree() { root = NULL; }

    void insert_at(T data, int position) {
        auto node = new Node<T>;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->top = NULL;
        if (root == NULL) {
            root = node;
            return;
        }
        auto parent = bfs(position);
        if (parent == NULL) {
            cout << "Incorrect position\n";
            return;
        }
        node->top = parent;
        if (parent->left == NULL) {
            parent->left = node;
        } else {
            auto tmp = parent->left;
            while (tmp->right != NULL) {
                tmp = tmp->right;
            }
            tmp->right = node;
        }
    }

    Node<T>* bfs(int index) {
        int current_index = 0;
        auto node{root};
        queue<Node<T>*> qq;
        qq.push(node);
        while (qq.size() > 0) {
            auto current = qq.front();
            ++current_index;
            if (current_index == index) return current;
            qq.pop();
            if (current->left != NULL) {
                qq.push(current->left);
            }
            while (current->right != NULL) {
                qq.push(current->right);
                current = current->right;
            }
        }
        return NULL;
    }

    void print_info(const Node<T>* node) {
        cout << "Value: " << node->data << endl;
        if (node->top) cout << "Parent: " << node->top->data << endl;
        if (node->left) cout << "Left: " << node->left->data << endl;
        if (node->right) cout << "Right: " << node->right->data << endl;
    }

    void print_tree() {
        auto node{root};
        queue<Node<T>*> qq;
        qq.push(node);
        while (qq.size() > 0) {
            auto current = qq.front();
            // print_info(current);
            cout << current->data << ' ';
            qq.pop();
            if (current->left != NULL) {
                qq.push(current->left);
            }
            while (current->right != NULL) {
                qq.push(current->right);
                current = current->right;
            }
        }
    }
};

auto main() -> int {
    auto r_tree = rooted_tree<int>();

    r_tree.insert_at(1, 0);
    r_tree.insert_at(2, 1);
    r_tree.insert_at(3, 1);
    r_tree.insert_at(4, 1);
    r_tree.insert_at(5, 2);
    r_tree.insert_at(6, 2);
    r_tree.insert_at(7, 3);
    r_tree.insert_at(8, 3);
    r_tree.insert_at(9, 3);
    r_tree.insert_at(10, 3);
    r_tree.insert_at(11, 4);
    r_tree.insert_at(12, 6);
    r_tree.insert_at(13, 9);
    r_tree.insert_at(14, 9);
    r_tree.insert_at(15, 4);

    r_tree.print_tree();

    return 0;
}
