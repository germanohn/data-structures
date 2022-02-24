#include <iostream>
using std::cout;


int SinglyLinkedList::get(int index) {
    Node* cur = this->head;
    for (int i = 0; i < index && cur != nullptr; i++) {
        cur = cur->next;
    }

    if (cur == nullptr) { // index is larger than the length of the linked list
        return -1;
    }
    return cur->val;

    //print();
}

// Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void SinglyLinkedList::insert_at_head(int val) {
    if (this->head == nullptr) { // the linked list is empty
        this->head = new Node(val);
        return;
    }

    // the linked list is not empty
    // create the new node that will be the head, and make its next pointer point to the current head
    Node* new_head = new Node(val);
    new_head->next = this->head;
    // change the head
    this->head = new_head;

    //print();
}

// Append a node of value val as the last element of the linked list.
void SinglyLinkedList::insert_at_tail(int val) {
    if (this->head == nullptr) { // the linked list is empty
        this->head = new Node(val);
        return;
    }

    // the linked list is not empty
    // traverse the linked list up to the last node
    Node* cur = this->head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    cur->next = new Node(val);

    //print();
}

// Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void SinglyLinkedList::insert_at_index(int index, int val) {
    if (index == 0) { // insert node at the beginning
        insert_at_head(val);
        return;
    }

    // at this point we have index > 0
    // now we find the previous node to the indexth node
    Node* prev = this->head;
    for (int i = 0; i < index - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    if (prev != nullptr) {
        Node* next = prev->next;
        prev->next = new Node(val, next);
    }

    //print();
}

// Delete the indexth node in the linked list, if the index is valid.
void SinglyLinkedList::delete_at_index(int index) {
    if (!index) { // delete the head node
        if (this->head == nullptr) { // linked list is empty
            return;
        }
        // linked list is not empty
        // change head to the next of head
        // delete the old head
        Node* deleted_node = this->head;
        head = head->next;
        delete deleted_node;
        //print();
        return;
    }

    // this point we have that index > 0
    // find the previous node to the indexth node
    Node* prev = this->head;
    for (int i = 0; i < index - 1 && prev != nullptr; i++) { // we want to stop when i == index-1
        prev = prev->next;
    }

    if (prev == nullptr || prev->next == nullptr) { // index is greater than the length
        return;
    }

    Node* pt_del = prev->next;
    prev->next = pt_del->next;
    delete pt_del;
    //print();
}


void SinglyLinkedList::print() {
    Node* cur = this->head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}