#include <iostream>
#include <utility>

struct Node {
  int value;
  struct Node *next;
  Node() : value(0), next(nullptr) {}
  Node(int val, Node *next) : value(val), next(next) {}
  explicit Node(int val) : value(val), next(nullptr) {}
};

class linked_list {
 private:
  Node *head;
  Node *tail;

 public:
  linked_list() {
    head = nullptr;
    tail = nullptr;
  }

  void push_back(int val) {
    auto node = new Node(val);
    if (!head) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }

  void insert(int val) {
    auto node = new Node(val, head);
    head = node;
    if (!tail) tail = node;
  }

  void insert_at(int position, int val) {
    if (position <= 1) return insert(val);

    auto previous = new Node();
    auto current = new Node();
    current = head;
    for (int i = 0; i < position; ++i) {
      std::exchange(previous, current);
      std::exchange(current, current->next);

      if (!current) return push_back(val);
    }
    auto node = new Node(val, current);
    previous->next = node;
  }

  void pop_front() {
    auto tmp = new Node();
    tmp = head;
    head = head->next;
    delete tmp;
  }

  void pop_back() {
    auto previous = new Node();
    auto current = new Node();
    auto tmp = new Node();
    current = head;
    while (current->next) {
      previous = current;
      current = current->next;
    }
    tmp = previous->next;
    previous->next = nullptr;
    tail = previous;
    delete tmp;
  }
  void delete_at(int position) {
    if (position <= 1) return pop_front();

    auto previous = new Node();
    auto current = new Node();
    auto tmp = new Node();
    current = head;
    for (int i = 1; i < position; ++i) {
      previous = current;
      current = current->next;

      if (!current->next) return pop_back();
    }
    tmp = current;
    previous->next = current->next;
    delete current;
    delete previous;
  }
};

int main() {
  linked_list list;
  list.insert(3);
  list.push_back(5);
  list.insert_at(-3, 2);
  list.insert_at(7, 8);
  list.insert_at(8, 9);
  list.pop_front();
  list.push_back(7);
  list.push_back(5);
  list.pop_back();
  list.delete_at(43);

  return 0;
}
