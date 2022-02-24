#ifndef LINKED_LIST_CLASS_H
#define LINKED_LIST_CLASS_H

#include <iostream>
using std::cout;


struct Node {
    int val;
    Node* next;

    Node(): val(0), next(nullptr) {}
    Node(int _val): val(_val), next(nullptr) {}
    Node(int _val, Node* _next): val(_val), next(_next) {}
};


class SinglyLinkedList {
    public:
        SinglyLinkedList(): head(nullptr) {}
        SinglyLinkedList(Node* _head): head(_head) {}

        // Get the value of the indexth node in the linked list. If the index is invalid, return -1.
        int get(int index);

        // Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        void insert_at_head(int val);

        // Append a node of value val as the last element of the linked list.
        void insert_at_tail(int val);

        // Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
        void insert_at_index(int index, int val);

        // Delete the indexth node in the linked list, if the index is valid.
        void delete_at_index(int index);

        void print() {}
    private:
        Node* head;
};

#endif