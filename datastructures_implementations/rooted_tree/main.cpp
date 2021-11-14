#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* top;
    Node<T>* left;
    Node<T>* right;
    int depth;
    bool deepest;
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
        } else if (node->left != NULL) {
            if (node->deepest) --height;
            node->left->top = node->top;
            node->top->left = node->left;
            delete node;
            return;
        }
        if (node->deepest) --height;
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

    /*
     *  I  hope i represented this tree correctly, it is not easy
     *  to visualize things as a comments. print_tree function should do better
     * work.
     *
     *                  1
     *                  |
     *         3 ------ 8 -------------- 4
     *         |        |                |
     *      |--       - |                |
     *      |         |                  |
     *      5 -- 16   7 - 21 - 9 - 10    11
     *           |           |
     *           12         -----
     *                     |    |
     *                    13   18
     *                          |
     *                          50
     *
     */

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
    r_tree.delete_node(50);
    r_tree.delete_node(18);
    // r_tree.delete_node(13);

    r_tree.print_tree();
    /*
    auto node = r_tree.bfs(50);
    cout << boolalpha;
    cout << "Node " << node->data << " is deepest: " << node->deepest << '\n';
    */
    cout << "Height: " << r_tree.get_height() << '\n';

    // PRINT_TREE RESULT:
    /*
     * Value: 1	     Parent: xx     Left Child: 3		 Right Sibling:
     * xx Value: 3	     Parent: 1	    Left Child: 5		 Right
     * Sibling: 8 Value: 8	     Parent: 1	    Left Child: 7
     * Right Sibling: 4 Value: 4	     Parent: 1	    Left Child: 11
     * Right Sibling: xx Value: 5	     Parent: 3	    Left Child: xx
     * Right Sibling: 16 Value: 16	 Parent: 3	    Left Child: 12
     * Right Sibling: xx Value: 7	     Parent: 8	    Left Child: xx
     * Right Sibling: 21 Value: 21	 Parent: 8	    Left Child: xx
     * Right Sibling: 9 Value: 9	     Parent: 8	    Left Child: 13
     * Right Sibling: 10 Value: 10	 Parent: 8	    Left Child: xx
     * Right Sibling: xx Value: 11	 Parent: 4	    Left Child: xx
     * Right Sibling: xx Value: 12	 Parent: 16	    Left Child: xx
     * Right Sibling: xx Value: 13	 Parent: 9	    Left Child: xx
     * Right Sibling: 18 Value: 18	 Parent: 9	    Left Child: 50
     * Right Sibling: xx Value: 50	 Parent: 18	    Left Child: xx
     * Right Sibling: xx
     *
     */

    return 0;
}
