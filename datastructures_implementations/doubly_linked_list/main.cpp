#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* previous;
};

template <typename T>
struct doubly_linked_list {
   private:
    Node<T>* head;
    Node<T>* tail;

   public:
    doubly_linked_list() {
        head = NULL;
        tail = NULL;
    }

    void insert(T value) {
        auto tmp = new Node<T>;
        tmp->data = value;
        tmp->next = NULL;
        tmp->previous = NULL;
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tmp->previous = tail;
            tail = tmp;
        }
    }

    void display() {
        auto tmp = new Node<T>;
        tmp = head;
        while (tmp != NULL) {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
};

auto main() -> int {
    doubly_linked_list<int> list;
    list.insert(5);
    list.insert(8);
    list.insert(9);
    list.display();

    return 0;
}
