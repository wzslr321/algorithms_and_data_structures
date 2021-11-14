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

    void insert_at(T data, T parent_data) {
        auto node = new Node<T>;
        node->top = NULL;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        if (root == NULL) {
            root = node;
            return;
        }
        auto top = bfs(parent_data);
        if (top == NULL) {
            cout << "There is no such a node\n";
            return;
        }
        node->top = top;
        if (top->left == NULL) {
            top->left = node;
            cout << "Inserted node with value: " << node->data
                 << " to: " << top->data << " as left child" << endl;
        } else {
            auto child = top->left;
            while (child->right != NULL) {
                child = child->right;
            }
            child->right = node;
            cout << "Inserted node with value: " << node->data
                 << " to: " << top->data << " as sibling of: " << child->data
                 << endl;
        }
    }

    Node<T>* bfs(T parent_data) {
        auto node = root;
        queue<Node<T>*> qq;
        qq.push(node);
        while (qq.size() > 0) {
            auto current = qq.front();
            if (current->data == parent_data) return current;
            qq.pop();
            if (current->left != NULL) {
                qq.push(current->left);
                current = current->left;
                while (current->right != NULL) {
                    qq.push(current->right);
                    current = current->right;
                }
            }
        }
        return NULL;
    }

    void print_tree() {}
};

auto main() -> int {
    auto r_tree = rooted_tree<int>();

    /*
     *
     *                  1
     *                  |
     *         2 ------ 3 --------- 4
     *         |        |           |
     *      |--       - |           |
     *      |        |              |
     *      5 -- 6   7 - 8 9 10     11
     *           |
     *           12
     *
     */

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
