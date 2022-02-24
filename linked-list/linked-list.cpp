#include <iostream>
#include "linked-list.h"
using std::cout;


Node* other_reverse_recursively(Node* p) {
    // we have reached the last node
	if (p->next == nullptr) {
        return p;
    }
    Node* head = other_reverse_recursively(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = nullptr; // in the case that p was the head of the linked list
    return head;
}

Node* reverse_linked_list_recursively(Node* head, Node* new_head_next /*= nullptr*/) {
    // the linked list is empty
    if (head == nullptr) {
        cout << "error: linked list is empty\n";
        return head;
    }

    // save the old head next
    Node* old_head_next = head->next;
    // reverse the head of the linked list
    head->next = new_head_next;
    if (old_head_next == nullptr) { // head was the last node to be reversed
        return head;
    } else { // reverse the remaining linked list
        return reverse_linked_list_recursively(old_head_next, head);
    }
}


Node* reverse_linked_list(Node* head) {
    /* the following case with one node is handled also in the while
    loop below
    // the linked list is empty
    if (head == nullptr) {
        cout << "error: linked list is empty\n";
        return head;
    }
    */

    /* the following case with one node is handled also in the while
    loop below
    // the linked list has just one node; so there is
    nothing to do if (head->next == nullptr) { return head;
    }
    */

    // reverse node by node of the list starting in the first node of
    // the list, then going to the second node, and so on.
    // the node to be reversed is always cur
    Node* prev = nullptr;
    Node* cur = head;
    while (cur != nullptr) {
        // save next of cur
        Node* next = cur->next;

        // reverse the node cur
        cur->next = prev;

        // go to the next node to reverse it
        prev = cur;
        cur = next;
    }

    // prev is the last node, and so the new head
    head = prev;

    return head;
}


Node* delete_node(Node* head, int pos) {
    // the linked list is empty
    if (head == nullptr) {
        cout << "error: linked list is empty\n";
        return head;
    }

    // delete the head of the linked list
    if (pos == 0) {
        // define the deleted_node
        Node* deleted_node = head;
        // update the new head
        head = head->next;
        // free the space of the deleted_node from memory
        delete deleted_node;
        return head;
    }

    // traverse the linked list until the (pos - 1)th node
    // - the value of i indicates the current node we are in the
    //   linked list; so we want the for loop to stop when i == pos -
    //   1, i.e., the stop condition must be i == pos - 1 or prev_del
    //   == nullptr
    Node* prev_del = head;
    for (int i = 0; i < pos - 1 && prev_del != nullptr; i++) {
        prev_del = prev_del->next;
    }

    // position pos does not exist in the linked list
    if (prev_del == nullptr || prev_del->next == nullptr) {
        cout << "error: position " << pos << " does not exist in the linked list\n";
        return head;
    }

    // define the deleted node
    Node* deleted_node = prev_del->next;

    // fix the next pointers to remove the node in position pos
    prev_del->next = deleted_node->next;

    // free the space of the deleted node from memory
    delete deleted_node;

    return head;
}


Node* insert_node(Node* head, int x, int pos) {
    // create the new node
	Node* new_node = new Node();
	new_node->val = x;
	new_node->next = nullptr;

	// if the insertion is at the beginning. This works even when the
	// list is empty
	if (pos == 0) {
        new_node->next = head;
		head = new_node;
		return head;
	}

	// traverse the linked list up to the (pos - 1)th position, i.e.,
	// stop when i == (pos - 1)
    Node* prev_new = head;
	for (int i = 0; i < pos - 1 && prev_new != nullptr; i++) {
        prev_new = prev_new->next;
    }

    if (prev_new == nullptr) {
        delete new_node;
        cout << "invalid insertion" << "\n";
        return head; // invalid insertion because there was less than pos + 1 (0-index) elements in the list
    }
    new_node->next = prev_new->next;
    prev_new->next = new_node;
    return head;
}


void print_linked_list(Node* head) {
    cout << "Linked List: ";
    if (head == nullptr) {
        cout << "empty\n";
        return;
    }
    for (Node* tmp = head; tmp != nullptr; tmp = tmp->next) {
        cout << tmp->val << " ";
    }
    cout << "\n";
}