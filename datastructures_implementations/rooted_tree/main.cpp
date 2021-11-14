#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* top;
    Node<T>* left;
    Node<T>* right;
    int depth;
};

template <typename T>
class rooted_tree {
   private:
    Node<T>* root;
    int height;

   public:
    rooted_tree() {
        root = NULL;
        height = 0;
    }

    void insert_at(T data, T parent_data) {
        auto node = new Node<T>;
        node->top = NULL;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->depth = 0;
        if (root == NULL) {
            root = node;
            ++height;
            // cout << "Inserted: " << node->data << " as a root\n";
            return;
        }
        auto top = bfs(parent_data);
        if (top == NULL) {
            cout << "There is no such a node\n";
            return;
        }
        node->top = top;
        if (top->left == NULL) {
            auto tmp = node;
            top->left = node;
            node->depth = top->depth + 1;
            height = max(height, node->depth + 1);
            // cout << "Inserted node with value: " << node->data
            // << " to: " << top->data << " as left child" << endl;
        } else {
            auto child = top->left;
            while (child->right != NULL) {
                child = child->right;
            }
            child->right = node;
            node->depth = top->depth + 1;
            // cout << "Inserted node with value: " << node->data
            // << " to: " << top->data << " as sibling of: " << child->data
            // << endl;
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

    int get_height() { return height; }

    void print_tree() {
        auto node = root;
        queue<Node<T>*> qq;
        qq.push(node);
        while (qq.size() > 0) {
            auto current = qq.front();
            cout << current->data << ' ';
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
        cout << endl;
    }
};

auto main() -> int {
    auto r_tree = rooted_tree<int>();

    /*
     *  I  hope i represented this tree correctly, it is not easy
     *  to visualize things as a comments. Real visualization is in README file.
     *
     *                  1
     *                  |
     *         2 ------ 3 -------------- 4
     *         |        |                |
     *      |--       - |                |
     *      |        |                   |
     *      5 -- 6   7 - 8 - 9 - 10     11
     *           |           |
     *           12         -----
     *                     |    |
     *                    13   14
     *                          |
     *                          15
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
    r_tree.insert_at(15, 14);

    r_tree.print_tree();
    cout << r_tree.get_height() << '\n';

    return 0;
}
