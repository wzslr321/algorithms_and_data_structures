#include <climits>
#include <iostream>
#include <queue>
#include <stack>

struct Node {
  int value;
  Node *left;
  Node *right;
  Node *parent;
  Node() : value(0), left(nullptr), right(nullptr), parent(nullptr) {}
  explicit Node(int val)
      : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class binary_tree {
 private:
  Node *root;
  int height;

 public:
  binary_tree() { root = NULL; }

  void insert(int value) {
    auto node = new Node(value);
    if (!root) {
      root = node;
      height = 0;
      return;
    }
    auto tmp = root;
    while (tmp->right != node && tmp->left != node) {
      if (node->value == tmp->value) break;
      if (node->value > tmp->value) {
        if (!tmp->right) {
          tmp->right = node;
          node->parent = tmp;
          if (!node->parent->left) ++height;
        } else {
          tmp = tmp->right;
        }
      } else {
        if (!tmp->left) {
          tmp->left = node;
          node->parent = tmp;
          if (!node->parent->right) ++height;
        } else {
          tmp = tmp->left;
        }
      }
    }
  }

  void remove(int value) {
    auto tmp = root;
    auto previous = new Node();
    while (true) {
      if (tmp->value == value) {
        if (previous->right) {
          if (previous->right->value == value) {
            previous->right = nullptr;
            delete tmp;
            if (!previous->left) --height;
          }
        }
        if (previous->left) {
          if (previous->left->value == value) {
            previous->left = nullptr;
            delete tmp;
            if (!previous->right) --height;
          }
        }
        if (root->value == value) {
          root = tmp->right;
          root->left = tmp->left;
          delete tmp;
          --height;
        }
        break;
      }
      if (tmp->value < value) {
        if (!tmp->right) break;
        previous = tmp;
        tmp = tmp->right;
      }
      if (tmp->value > value) {
        if (!tmp->left) break;
        previous = tmp;
        tmp = tmp->left;
      }
    }
  }

  bool search(int value) {
    auto tmp = root;
    while (true) {
      if (tmp->value == value) return true;
      if (value > tmp->value) {
        if (!tmp->right)
          return false;
        else
          tmp = tmp->right;
      } else {
        if (!tmp->left)
          return false;
        else
          tmp = tmp->left;
      }
    }
  }

  bool search_recursively(Node *current_root, int value) {
    if (!current_root) return false;
    if (current_root->value == value) return true;
    auto left = search_recursively(current_root->left, value);
    auto right = search_recursively(current_root->right, value);
    // it can be one liner, it looks ugly though so I did it this way here
    return left || right;
  }

  void dfs() {
    auto node{root};
    std::stack<Node *> st;
    st.push(node);
    while (st.size() > 0) {
      auto current{st.top()};
      st.pop();
      if (current->right) st.push(current->right);
      if (current->left) st.push(current->left);
    }
  }

  void bfs() {
    auto node{root};
    std::queue<Node *> qq;
    qq.push(node);
    while (qq.size() > 0) {
      auto current{qq.front()};
      qq.pop();
      if (current->left) qq.push(current->left);
      if (current->right) qq.push(current->right);
    }
  }

  int sum_recursively(Node *current_root) {
    if (!current_root) return 0;
    auto left_subtree = sum_recursively(current_root->left);
    auto right_subtree = sum_recursively(current_root->right);
    return current_root->value + left_subtree + right_subtree;
  }

  int max_root_to_leaf_sum(Node *current_root) {
    if (!current_root) return INT_MIN;
    if (!current_root->left && !current_root->right) return current_root->value;

    auto max_left = INT_MIN;
    auto max_right = INT_MIN;
    max_left = max_root_to_leaf_sum(current_root->left);
    max_right = max_root_to_leaf_sum(current_root->right);
    auto max_subtree = std::max(max_left, max_right);
    return current_root->value + max_subtree;
  }

  Node *get_root() { return root; }

  int get_height() { return height; }
};

auto main() -> int {
  binary_tree tree;
  tree.insert(20);
  tree.insert(15);
  tree.insert(30);
  tree.insert(10);
  tree.insert(18);
  tree.insert(7);
  tree.dfs();
  tree.bfs();
  tree.search(7);
  tree.search_recursively(tree.get_root(), 3);
  tree.sum_recursively(tree.get_root());
  tree.max_root_to_leaf_sum(tree.get_root());
  tree.get_height();

  return 0;
}
