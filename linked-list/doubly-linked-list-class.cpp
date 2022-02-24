#include "doubly-linked-list-class.h"
#include <iostream>


// it is equal to SinglyLinkedList::get(int index)
int DoublyLinkedList::get(int index) {
    DoubleNode* cur = head;
    for (int i = 0; i < index && cur != nullptr; i++) {
        cur = cur->next;
    }

    if (cur == nullptr) {
        return -1;
    }

    return cur->val;
}


void DoublyLinkedList::insert_at_head(int val) {
    if (head == nullptr) { // doubly linked list is empty
        head = new DoubleNode(val);
        return;
    }

    DoubleNode* old_head = head;
    head = new DoubleNode(val, nullptr, old_head);
    old_head->prev = head;
}


void DoublyLinkedList::insert_at_tail(int val) {
    if (head == nullptr) { // doubly linked list is empty
        head = new DoubleNode(val);
        return;
    }

    // traverse the linked list until its last node, the current tail
    DoubleNode* cur = DoublyLinkedList::head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    DoubleNode* new_tail = new DoubleNode(val, cur, nullptr);
    cur->next = new_tail;
}


void DoublyLinkedList::insert_at_index(int index, int val) {
    if (index == 0) {
        insert_at_head(val);
        return;
    }

    DoubleNode* prev = DoublyLinkedList::head;
    for (int i = 0; i < index - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    if (prev != nullptr) {
        DoubleNode* next = prev->next;
        DoubleNode* new_node = new DoubleNode(val, prev, next);
        prev->next = new_node;
        if (next != nullptr) { // otherwise new_node is the new tail
            next->prev = new_node;
        }
    }
}


void DoublyLinkedList::delete_at_index(int index) {
    if (index == 0) {
        if (DoublyLinkedList::head == nullptr) {
            return;
        }
        DoubleNode* deleted = DoublyLinkedList::head;
        DoublyLinkedList::head = deleted->next;
        DoublyLinkedList::head->prev = nullptr;
        delete deleted;
        return;
    }

    DoubleNode* prev = DoublyLinkedList::head;
    for (int i = 0; i < index - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    if (prev != nullptr) {
        DoubleNode* deleted = prev->next;
        DoubleNode* next = deleted->next;
        prev->next = next;
        if (next != nullptr) { // otherwise deleted was the tail and next does not exist
            next->prev = prev;
        }
        delete deleted;
    }
}


void DoublyLinkedList::print() {
    DoubleNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}


void DoublyLinkedList::reverse_print() {
    if (head == nullptr) { // doubly linked list is empty
        return;
    }

    // traverse the linked list until its tail
    DoubleNode* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->prev;
    }
    std::cout << "\n";
}