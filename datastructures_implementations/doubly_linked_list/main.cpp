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

    void insert_at(int position, T value) {
        if (position <= 1) {
            return insert(value);
        }
        auto current = new Node<T>;
        auto tmp = new Node<T>;
        tmp->data = value;
        for (auto i{1}; i < position; ++i) {
            if (current->next == NULL) {
                tmp->previous = current;
                current->next = tmp;
                tail = tmp;
            } else {
                current = current->next;
            }
        }
        tmp->next = current->next;
        current->next = tmp;
        tmp->previous = current;
    }

    void display() {
        auto tmp = new Node<T>;
        auto tmp2 = new Node<T>;
        tmp = head;
        tmp2 = tmp;
        printf("LIST: ");
        while (tmp != NULL) {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");

        while (tmp2 != NULL) {
            printf("%d ", tmp2->data);
            if (tmp2->previous) printf("previous: %d \t", tmp2->previous->data);
            if (tmp2->next) printf("next: %d ", tmp2->next->data);
            tmp2 = tmp2->next;
            printf("\n");
        }
        printf("\n");
    }
};

auto main() -> int {
    doubly_linked_list<int> list;
    list.insert(5);
    list.insert(8);
    list.insert(2);
    list.insert(9);
    list.display();

    return 0;
}
