#ifndef DOUBLY_LINKED_LIST_CLASS_H
#define DOUBLY_LINKED_LIST_CLASS_H


struct DoubleNode {
    int val;
    DoubleNode* prev;
    DoubleNode* next;

    DoubleNode() : val(0), prev(nullptr), next(nullptr) {}
    DoubleNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
    DoubleNode(int _val, DoubleNode* _prev, DoubleNode* _next) : val(_val), prev(_prev), next(_next) {}
};


class DoublyLinkedList {
    public:
        DoublyLinkedList() : head(nullptr) {}
        DoublyLinkedList(DoubleNode* _head) : head(_head) {}

        int get(int index);
        void insert_at_head(int val);
        void insert_at_tail(int val);
        void insert_at_index(int index, int val);
        void delete_at_index(int index);
        void print();
        void reverse_print();
    private:
        DoubleNode* head;
};

#endif