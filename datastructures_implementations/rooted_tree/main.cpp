#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename T> struct Node {
  T data;
  Node<T> *top;
  Node<T> *left;
  Node<T> *right;
  int depth;
};

template <typename T> class rooted_tree {
 private:
  Node<T> *root;
  int height;
  Node<T> *deepest;

 public:
  rooted_tree() {
    root = nullptr;
    height = 0;
    deepest = nullptr;
  }

  void insert_at(T data, T parent_data) {
    auto node = new Node<T>;
    node->top = nullptr;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->depth = 0;
    if (root == nullptr) {
      root = node;
      deepest = node;
      return;
    }
    auto top = bfs(parent_data);
    if (top == nullptr)
      return;
    node->top = top;
    if (top->left == nullptr) {
      top->left = node;
      node->depth = top->depth + 1;
      if (node->depth > deepest->depth)
        deepest = node;
    } else {
      auto child = top->left;
      while (child->right != nullptr) {
        child = child->right;
      }
      child->right = node;
      node->depth = top->depth + 1;
    }
  }

  Node<T> *bfs(T parent_data) {
    auto node = root;
    queue<Node<T> *> qq;
    qq.push(node);
    while (qq.size() > 0) {
      auto current = qq.front();
      if (current->data == parent_data)
        return current;
      qq.pop();
      if (current->left != nullptr) {
        qq.push(current->left);
        current = current->left;
        while (current->right != nullptr) {
          qq.push(current->right);
          current = current->right;
        }
      }
    }
    return nullptr;
  }

  Node<T> *dfs(int depth) {
    auto node = root;
    stack<Node<T> *> st;
    st.push(node);
    while (st.size() > 0) {
      auto current = st.top();
      if (current->depth == depth && current != deepest)
        return current;
      st.pop();
      if (current->left != nullptr) {
        st.push(current->left);
        current = current->left;
        while (current->right != nullptr) {
          st.push(current->right);
          current = current->right;
        }
      }
    }
    return nullptr;
  }

  void update_height_in_subtree(Node<T> *st_root) {
    auto node = st_root;
    stack<Node<T> *> st;
    st.push(node);
    while (st.size() > 0) {
      auto current = st.top();
      current->depth -= 1;
      st.pop();
      if (current->left != nullptr) {
        st.push(current->left);
        current = current->left;
        while (current->right != nullptr) {
          st.push(current->right);
          current = current->right;
        }
      }
    }
  }

  int get_height() { return deepest->depth; }
  Node<T> *get_deepest() { return deepest; }

  void delete_node(int value) {
    auto node = bfs(value);
    if (node == nullptr)
      return;
    if (node->top == nullptr) {
      if (node->left == nullptr) {
        root = nullptr;
        deepest = nullptr;
        delete node;
        return;
      } else {
        root = node->left;
        root->top = nullptr;
        auto tmp = root->right;
        while (tmp != nullptr) {
          tmp->top = root;
          tmp = tmp->right;
        }
        tmp = root->left;
        while (tmp->right != nullptr) {
          tmp = tmp->right;
        }

        tmp->right = root->right;
        root->right = nullptr;
        update_height_in_subtree(root);
        return;
      }
    }
    if (node->right != nullptr) {
      // deepest = node->right;
      auto tmp = node->top->left;
      if (tmp != node) {
        while (tmp->right != node) {
          tmp = tmp->right;
        }
      }
      tmp->right = node->right;
      if (node->top->left == node) {
        node->top->left = node->right;
      }
      if (node->left != nullptr) {
        node->right->left = node->left;
        tmp = node->left;
        while (tmp != nullptr) {
          tmp->top = node->right;
          tmp = tmp->right;
        }
      }
      delete node;
      return;
    }
    auto eq = dfs(node->depth);
    if (node->left != nullptr) {
      if (node == deepest) {
        if (eq != nullptr) {
          deepest = eq;
        } else {
          deepest = node->left;
        }
      }
      node->left->top = node->top;
      node->top->left = node->left;
      delete node;
      return;
    }
    if (node == deepest) {
      if (eq != nullptr) {
        deepest = eq;
      } else {
        deepest = node->top;
      }
    }
    if (node->top->left == node) {
      node->top->left = nullptr;
    } else {
      auto tmp = node->top->left;
      while (tmp->right != node) {
        tmp = tmp->right;
      }
      tmp->right = nullptr;
    }
    node->top = nullptr;
    delete node;
  }

  void print_node(const Node<T> *node) {
    cout << "Value: " << node->data << '\t';
    if (node->top != nullptr)
      cout << " Parent: " << node->top->data << '\t';
    else
      cout << " Parent: xx " << '\t';
    if (node->left != nullptr)
      cout << " Left Child: " << node->left->data << '\t' << '\t';
    else
      cout << " Left Child: xx" << '\t' << '\t';

    if (node->right != nullptr)
      cout << " Right Sibling: " << node->right->data;
    else
      cout << " Right Sibling: xx";
    cout << '\n';
  }

  void print_tree() {
    auto node = root;
    queue<Node<T> *> qq;
    qq.push(node);
    while (qq.size() > 0) {
      auto current = qq.front();
      print_node(current);
      qq.pop();
      if (current->left != nullptr) {
        qq.push(current->left);
        current = current->left;
        while (current->right != nullptr) {
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
  r_tree.insert_at(99, 7);
  r_tree.print_tree();
  cout << "Height: " << r_tree.get_height() << '\n';
  auto deepest = r_tree.get_deepest();
  cout << "Deepest node: " << deepest->data << '\n';
  r_tree.delete_node(7);

  r_tree.print_tree();

  cout << "Height: " << r_tree.get_height() << '\n';
  deepest = r_tree.get_deepest();
  cout << "Deepest node: " << deepest->data << '\n';

  return 0;
}
