#include <iostream>
#include <utility>

struct Node {
  int value;
  Node *next;
  Node *previous;
  Node() : value(0), next(nullptr), previous(nullptr) {}
  explicit Node(int val) : value(val), next(nullptr), previous(nullptr) {}
  Node(int val, Node *next) : value(val), next(next), previous(nullptr) {}
  Node(int val, Node *next, Node *previous)
      : value(val), next(next), previous(previous) {}
};

struct doubly_linked_list {
 private:
  Node *head;
  Node *tail;

 public:
  doubly_linked_list() {
    head = nullptr;
    tail = nullptr;
  }

  void insert(int value) {
    auto node = new Node(value);
    if (!head) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      node->previous = tail;
      tail = node;
    }
  }

  void insert_at(int position, int value) {
    if (position <= 1) return insert(value);

    auto current = new Node();
    auto node = new Node();
    node->value = value;
    for (int i = 1; i < position; ++i) {
      if (!current->next) {
        node->previous = current;
        current->next = node;
        tail = node;
      } else {
        current = current->next;
      }
    }
    node->next = current->next;
    current->next = node;
    node->previous = current;
  }
};

auto main() -> int {
  doubly_linked_list list;
  list.insert(5);
  list.insert(8);
  list.insert(2);
  list.insert(9);
  list.insert(1);
  list.insert(12);
  list.insert(143);
  list.insert(15);
  return 0;
}
