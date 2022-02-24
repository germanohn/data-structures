#include "doubly-linked-list-class.h"
#include <iostream>


void DoublyLinkedList::InsertAtHead(int val) {
    if (head == nullptr) { // doubly linked list is empty
        head = new DoublyNode(val);
        return;
    }

    DoublyNode* old_head = head;
    head = new DoublyNode(val, nullptr, old_head);
    old_head->prev = head;
}


void DoublyLinkedList::InsertAtTail(int val) {
    if (head == nullptr) { // doubly linked list is empty
        head = new DoublyNode(val);
        return;
    }

    // traverse the linked list until its last node, the current tail
    DoublyNode* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    DoublyNode* new_tail = new DoublyNode(val, cur, nullptr);
    cur->next = new_tail;
}


void DoublyLinkedList::Print() {
    DoublyNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}


void DoublyLinkedList::ReversePrint() {
    if (head == nullptr) { // doubly linked list is empty
        return;
    }

    // traverse the linked list until its tail
    DoublyNode* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->prev;
    }
    std::cout << "\n";
}