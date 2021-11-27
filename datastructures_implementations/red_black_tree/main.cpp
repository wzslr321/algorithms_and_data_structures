#include <cstdlib>
#include <iostream>

struct Node {
    char color;
    int value;
    Node *parent;
    Node *left;
    Node *right;

    explicit Node(int x)
            : color('r'), value(x), parent(nullptr), left(nullptr), right(nullptr) {}
};

class red_black_tree {
private:
    Node *root;

public:
    red_black_tree() { root = nullptr; }

    const Node *get_root() { return root; }

    Node *find_parent(Node *node, int value) {
        if (!node) return node;
        auto tmp = node;
        auto direction = node->value > value ? node->left : node->right;
        node = find_parent(direction, value);
        if (!node) return tmp;
        return node;
    }

    bool is_uncle_red(Node *node) {
        if (!node) return false;

        bool is_left_red = node->left && node->left->color == 'r';
        bool is_right_red = node->right && node->right->color == 'r';

        if (is_left_red && is_right_red) return true;
        return false;
    }

    void rotate_left(Node *node) {
        auto parent = node->parent;

        node->color = 'b';
        parent->color = 'r';
        parent->right = node->left;
        if (node->left) node->left->parent = parent;
        node->left = parent;

        if (parent->parent) {
            node->parent = parent->parent;

            if (node->parent->value > parent->value)
                parent->parent->left = node;
            else
                parent->parent->right = node;

        } else {
            node->parent = nullptr;
            root = node;
        }
        parent->parent = node;
    }

    void rotate_right(Node *node) {
        auto parent = node->parent;

        parent->color = 'r';
        node->color = 'b';
        parent->left = node->right;
        if (node->right) node->right->parent = parent;
        node->right = parent;

        if (parent->parent) {
            node->parent = parent->parent;

            if (node->parent->value > parent->value)
                parent->parent->left = node;
            else
                parent->parent->right = node;

        } else {
            node->parent = nullptr;
            root = node;
        }

        parent->parent = node;
    }

    void single_rotate_left(Node* node) {
        auto parent = node->parent;
        auto tmp = node->right->left;
        node->parent = node->right;
        parent->left = node->right;
        node->right->parent = parent;
        node->right->left = node;
        node->right = tmp;
        rotate_right(node->parent);
    }

    void single_rotate_right(Node* node) {
        auto parent = node->parent;
        auto tmp = node->left->right;
        node->parent = node->left;
        parent->right = node->left;
        node->left->parent = parent;
        node->left->right= node;
        node->left = tmp;
        rotate_left(node->parent);
    }

    void push_blackness(Node *node) {
        node->left->color = 'b';
        node->right->color = 'b';
        if (node != root) node->color = 'r';
    }

    void insert_root(Node *node) {
        node->color = 'b';
        root = node;
    }

    void insert_to_parent(Node *node, Node *parent) {
        node->parent = parent;
        if (node->value > parent->value)
            parent->right = node;
        else
            parent->left = node;
    }

    void insert(int value) {
        auto node = new Node(value);
        if (!root) return insert_root(node);

        const auto &parent = find_parent(root, value);
        if (!parent) return;
        insert_to_parent(node, parent);

        auto grandparent = parent->parent;
        // Inserted node and it's parent are red - actions are needed.
        if (parent->color == 'r') {
            // Grandparent can't be null here

            // If uncle of inserted node is also red, push_blackness is enough
            if (is_uncle_red(grandparent)) return push_blackness(grandparent);

            // Otherwise, rotation is needed.

            // Node and Parent are both right childs --> rotate left -- 1st scenario
            if (parent->right == node && grandparent->right == parent)
                return rotate_left(parent);
            if (parent->left == node && grandparent->left == parent)
                return rotate_right(parent);
            if (parent->right == node && grandparent->left == parent)
                return single_rotate_left(parent);
            if (parent->left == node && grandparent->right == parent)
                return single_rotate_right(parent);

        }
    }
};

void display(const Node *node);

auto main() -> int {
    red_black_tree tree{};

    tree.insert(25);
    tree.insert(50);
    tree.insert(40);
    tree.insert(60);
    tree.insert(70);
    tree.insert(55);


    display(tree.get_root());

    return 0;
}

void print_node(const Node *node) {
    std::cout << "Value: " << node->value << '\t';
    std::cout << "Left Child: ";
    if (node->left != nullptr) {
        std::cout << node->left->value << '\t';
    } else {
        std::cout << node->left << '\t';
    }
    std::cout << "Right child: ";
    if (node->right != nullptr) {
        std::cout << node->right->value << '\t';
    } else {
        std::cout << node->right << '\t';
    }
    std::cout << "Parent: ";
    if (node->parent != nullptr) {
        std::cout << node->parent->value << '\t';
    } else {
        std::cout << node->parent << '\t';
    }
    std::cout << "Color: " << (node->color == 'r' ? "red" : "black") << '\n';
}

void display(const Node *node) {
    if (!node) {
        std::cout << "Tree is empty\n";
        return;
    }
    print_node(node);
    if (node->left) {
        display(node->left);
    }
    if (node->right) {
        display(node->right);
    }
}
