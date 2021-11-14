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
    Node<T>* deepest;

   public:
    rooted_tree() {
        root = NULL;
        height = 0;
        deepest = NULL;
    }

    void insert_at(T data, T parent_data) {
        auto node = new Node<T>;
        node->top = NULL;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->depth = 0;
        node->deepest = false;
        if (root == NULL) {
            root = node;
            ++height;
            return;
        }
        auto top = bfs(parent_data);
        if (top == NULL) return;
        node->top = top;
        if (top->left == NULL) {
            top->left = node;
            node->depth = top->depth + 1;
            height = max(height, node->depth);
            if (height == node->depth) node->deepest = true;
        } else {
            auto child = top->left;
            while (child->right != NULL) {
                child = child->right;
            }
            child->right = node;
            node->depth = top->depth + 1;
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

    Node<T>* dfs(int depth) {
        auto node = root;
        stack<Node<T>*> st;
        st.push(node);
        while (st.size() > 0) {
            auto current = st.top();
            if (current->depth == depth) return current;
            st.pop();
            if (current->left != NULL) {
                st.push(current->left);
                current = current->left;
                while (current->right != NULL) {
                    st.push(current->right);
                    current = current->right;
                }
            }
        }
        return NULL;
    }

    int get_height() { return height; }

    void delete_node(int value) {
        auto node = bfs(value);
        if (node == NULL) return;
        if (node->top == NULL) {
            root = NULL;
            height = 0;
            delete node;
            return;
        }
        if (node->right != NULL) {
            node->right->deepest = true;
            node->top->left = node->right;
            if (node->left != NULL) {
                node->left->top = node->right;
            }
            delete node;
            return;
        }
        auto eq = dfs(node->depth);
        if (node->left != NULL) {
            if (node->deepest) {
                if (eq == NULL) {
                    node->left->deepest = true;
                    --height;
                } else {
                    eq->deepest = true;
                }
            }
            node->left->top = node->top;
            node->top->left = node->left;
            delete node;
            return;
        }
        if (node->deepest) {
            if (eq == NULL) {
                --height;
            } else {
                eq->deepest = true;
            }
        }
        if (node->top->left == node) {
            node->top->left = NULL;
        } else {
            auto tmp = node->top->left;
            while (tmp->right != node) {
                tmp = tmp->right;
            }
            tmp->right = NULL;
        }
        node->top = NULL;
        delete node;
    }

    void print_node(const Node<T>* node) {
        cout << "Value: " << node->data << '\t';
        if (node->top != NULL)
            cout << " Parent: " << node->top->data << '\t';
        else
            cout << " Parent: xx " << '\t';
        if (node->left != NULL)
            cout << " Left Child: " << node->left->data << '\t' << '\t';
        else
            cout << " Left Child: xx" << '\t' << '\t';

        if (node->right != NULL)
            cout << " Right Sibling: " << node->right->data;
        else
            cout << " Right Sibling: xx";
        cout << '\n';
    }

    void print_tree() {
        auto node = root;
        queue<Node<T>*> qq;
        qq.push(node);
        while (qq.size() > 0) {
            auto current = qq.front();
            print_node(current);
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
        cout << '\n';
    }
};

auto main() -> int {
    auto r_tree = rooted_tree<int>();

    r_tree.insert_at(1, 0);
    r_tree.insert_at(3, 1);
    r_tree.insert_at(8, 1);
    r_tree.insert_at(4, 1);
    r_tree.insert_at(5, 3);
    r_tree.insert_at(16, 3);
    r_tree.insert_at(7, 8);
    r_tree.insert_at(21, 8);
    r_tree.insert_at(9, 8);
    r_tree.insert_at(10, 8);
    r_tree.insert_at(11, 4);
    r_tree.insert_at(12, 16);
    r_tree.insert_at(13, 9);
    r_tree.insert_at(18, 9);
    r_tree.insert_at(50, 18);
    r_tree.print_tree();
    // r_tree.delete_node(50);
    // r_tree.delete_node(18);
    // r_tree.delete_node(13);

    r_tree.print_tree();
    auto node = r_tree.bfs(50);
    cout << boolalpha;
    cout << "Depth: " << node->depth << ' ' << node->deepest << '\n';

    cout << "Height: " << r_tree.get_height() << '\n';

    return 0;
}
