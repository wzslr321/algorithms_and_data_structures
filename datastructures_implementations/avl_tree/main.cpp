#include <iostream>

struct Node {
  int value;
  Node *left = nullptr;
  Node *right = nullptr;
  Node *parent = nullptr;
  int height = 1;
};

struct avl_tree {
 private:
  Node *root;
  int height;

 public:
  avl_tree() {
    root = nullptr;
    height = 0;
  }

  Node *get_root() { return root; }
  int get_height(Node *node) { return node->height; }

  void print_node(Node *node) {
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
    std::cout << "Height: " << node->height << '\n';
  }

  void dfs(Node *node) {
    print_node(node);
    if (node->left) {
      dfs(node->left);
    }
    if (node->right) {
      dfs(node->right);
    }
  }

  Node *dfs(Node *node, int value) {
    if (!node || node->value == value) return node;
    auto left = dfs(node->left, value);
    auto right = dfs(node->right, value);
    return !left ? right : left;
  }

  std::pair<Node *, Node *> find_max_in_subtree(Node *node) {
    if (!node) return std::pair<Node *, Node *>{nullptr, nullptr};
    while (node->right) {
      node = node->right;
    }
    return std::pair<Node *, Node *>{node, node->parent};
  }

  Node *search_parent(Node *node, int value) {
    if (!node) return node;
    if (node->value > value) {
      auto tmp = node;
      node = search_parent(node->left, value);
      if (!node) return tmp;
    } else {
      auto tmp = node;
      node = search_parent(node->right, value);
      if (!node) return tmp;
    }
    return node;
  }

  void ufs(Node *node, bool insert = false) {
    if (!node) return;
    auto left_height = 0;
    auto right_height = 0;
    if (node->left) left_height = node->left->height;
    if (node->right) right_height = node->right->height;

    if (insert) node->height = std::max(left_height, right_height) + 1;

    std::cout << "UFS: " << node->value << ' ' << left_height << ' '
              << right_height << '\n';

    auto tmp2 = node;
    auto tmp = node->parent;
    if (left_height > right_height + 1) {
      if (node->parent) {
        node->parent->left = node->left;
        node->parent->height -= 1;
      }
      node->parent = node->left;
      auto lsub = node->left->right;
      if (lsub) lsub->parent = node;
      node->left->right = node;
      node->left->parent = tmp;
      node->left->height -= 1;
      node->left = lsub;
      node->left = nullptr;
      if (node->left) {
        if (node->right) {
          node->height = std::max(node->left->height, node->right->height) + 1;
        } else {
          node->height = node->left->height + 1;
        }
      } else {
        if (node->right) {
          node->height = node->right->height + 1;
        } else {
          node->height -= 2;
        }
      }
    }
    if (right_height > left_height + 1) {
      if (node->parent) {
        node->parent->right = node->right;
        node->parent->height -= 1;
      }
      node->parent = node->right;
      auto rsub = node->right->left;
      if (rsub) rsub->parent = node;
      node->right->left = node;
      node->right->parent = tmp;
      node->right->height -= 1;
      node->right = node->right->left;
      node->right = rsub;
      if (node->left) {
        if (node->right) {
          node->height = std::max(node->left->height, node->right->height) + 1;
        } else {
          node->height = node->left->height + 1;
        }
      } else {
        if (node->right) {
          node->height = node->right->height + 1;
        } else {
          node->height -= 2;
        }
      }
    }
    if (!tmp) root = node;
    if (root->parent) root = root->parent;
    node = node->parent;
    ufs(node, insert);
    // if (tmp2->parent) tmp2->parent->left = tmp2;
  }

  void insert(int value) {
    auto node = new Node{};
    node->value = value;
    if (!root) {
      root = node;
      return;
    }
    const auto &parent = search_parent(root, value);
    if (!parent) return;
    node->parent = parent;
    if (parent->value > node->value) {
      parent->left = node;
    } else {
      parent->right = node;
    }
    ufs(parent, true);
  }

  void delete_leaf(Node *node) {
    if (!node->parent) root = nullptr;

    if (node == node->parent->left) {
      if (!node->parent->right) node->parent->height -= 1;
      node->parent->left = nullptr;
    } else {
      if (!node->parent->left) node->parent->height -= 1;
      node->parent->right = nullptr;
    }
    ufs(node->parent);

    node->parent = nullptr;
    delete node;
  }

  void remove(int value) {
    //
    // remember to udpate height smh
    //
    const auto &node = dfs(root, value);
    if (!node) return;
    const auto &max_node_pair = find_max_in_subtree(node->left);
    const auto &child = max_node_pair.first;
    const auto &parent = max_node_pair.second;
    if (child) {
      std::cout << "TO REMOVE: " << child->value << '\n';
    }
    if (parent) {
      std::cout << "WITH PARENT " << parent->value << '\n';
    }
    if (child) {
      node->value = child->value;
      if (child == parent->left) {
        parent->left = child->left;
      } else {
        if (!parent->left) parent->height -= 1;
        parent->right = child->left;
      }
    } else {
      if (node->right) {
        node->value = node->right->value;
        node->right->parent = nullptr;
        delete node->right;
      } else {
        delete_leaf(node);
      }
    }
    if (parent) {
      std::cout << "\nPARENT: " << parent->value << '\n';
    }
    ufs(parent);
  }
};

auto main() -> int {
  avl_tree tree{};
  tree.insert(5);
  tree.insert(4);
  tree.insert(3);
  tree.insert(2);
  tree.insert(1);
  tree.insert(6);
  tree.insert(10);
  tree.insert(15);
  tree.insert(16);
  tree.insert(19);
  tree.insert(21);

  tree.dfs(tree.get_root());
  std::cout << "\nHeight: " << tree.get_height(tree.get_root()) << '\n';

  tree.remove(1);
  tree.remove(3);

  std::cout << "\n\n";
  tree.dfs(tree.get_root());

  std::cout << "\nHeight: " << tree.get_height(tree.get_root()) << '\n';

  return 0;
}
