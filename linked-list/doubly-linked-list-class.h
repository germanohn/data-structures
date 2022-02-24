#ifndef DOUBLY_LINKED_LIST_CLASS_H
#define DOUBLY_LINKED_LIST_CLASS_H


struct DoublyNode {
    int val;
    DoublyNode* prev;
    DoublyNode* next;

    // constructors
    DoublyNode() : val(0), prev(nullptr), next(nullptr) {}
    DoublyNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
    // the following two constructors cannot both exist; and to write
    // only one of them also does not make sense
    // DoublyNode(int _val, DoublyNode* _prev) : val(_val), prev(_prev), next(nullptr) {}
    // DoublyNode(int _val, DoublyNode* _next) : val(_val), prev(nullptr), next(_next) {}
    DoublyNode(int _val, DoublyNode* _prev, DoublyNode* _next) : val(_val), prev(_prev), next(_next) {}
};


class DoublyLinkedList {
    public:
        // constructors
        DoublyLinkedList() : head(nullptr) {}
        DoublyLinkedList(DoublyNode* _head) : head(_head) {}

        // functions
        void InsertAtHead(int val);
        void InsertAtTail(int val);
        void Print();
        void ReversePrint();
    private:
        DoublyNode* head;
};

#endif