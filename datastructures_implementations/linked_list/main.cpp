#include <bits/stdc++.h>

template <typename T>
struct node {
    T data;
    struct node* next;
};

template <typename T>
class linked_list {
   private:
    node<T>* head;
    node<T>* tail;

   public:
    linked_list() {
        head = NULL;
        tail = NULL;
    }

    void push_back(T val) {
        auto tmp{new node<T>};
        tmp->data = val;
        tmp->next = NULL;
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
    }

    void insert(T val) {
        auto tmp{new node<T>};
        tmp->data = val;
        tmp->next = head;
        head = tmp;
        if (tail == NULL) {
            tail = tmp;
        }
    }

    void insert_at(int position, T val) {
        if (position < 2) {
            insert(val);
            return;
        }
        auto previous{new node<T>};
        auto current{new node<T>};
        auto tmp{new node<T>};
        current = head;
        for (auto i{1}; i < position; ++i) {
            previous = current;
            current = current->next;
            if (current == NULL) {
                push_back(val);
                return;
            };
        }
        tmp->data = val;
        previous->next = tmp;
        tmp->next = current;
    }

    void pop_front() {
        /*
         * It can be done only with / head = head->next \
         * because of memory leaks, previous head would still
         * be out there in the memory. We have to keep track of it
         * in order to delete it after updating the head.
         */

        auto tmp{new node<T>};
        tmp = head;
        head = head->next;
        delete tmp;
    }

    void pop_back() {
        auto previous{new node<T>};
        auto current{new node<T>};
        auto tmp{new node<T>};
        current = head;
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        tmp = previous->next;
        previous->next = NULL;
        tail = previous;
        delete tmp;
    }

    void delete_at(int position) {
        if (position < 2) {
            pop_front();
            return;
        }
        auto previous{new node<T>};
        auto current{new node<T>};
        auto tmp{new node<T>};
        current = head;
        for (auto i{1}; i < position; ++i) {
            previous = current;
            current = current->next;
            if (current->next == NULL) {
                pop_back();
                return;
            }
        }
        tmp = current;
        previous->next = current->next;
        delete current;
    }

    void display() {
        auto tmp{new node<T>};
        tmp = head;
        while (tmp != NULL) {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
};

int main() {
    linked_list<int> list;
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
    list.display();
    return 0;
}
