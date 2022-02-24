#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int val;
    Node* next;
};


// - Input: Receive the head "head" of the linked list
// - Task: Reverse the linked list so that the head of the linked list
//   is the last node, and the second node is the second last node,
//   and so on. Do that using a recursive approach
// - Output: return the the head of the reversed linked list
Node* other_reverse_recursively(Node* p);


// - Input: Receive the head "head" of the linked list and a pointer
//   new_head_next to the new next of the head
// - Task: Reverse the linked list so that the head of the linked list
//   is the last node, and the second node is the second last node,
//   and so on. Do that using a recursive approach
// - Output: return the the head of the reversed linked list
Node* reverse_linked_list_recursively(Node* head, Node* new_head_next = nullptr);


// - Input: Receive the head "head" of the linked list
// - Task: Reverse the linked list so that the head of the linked list
//   is the last node, and the second node is the second last node,
//   and so on.
// - Output: return the the head of the reversed linked list
Node* reverse_linked_list(Node* head);

// - Input: Receive the head "head" of the linked list, and a integer
//   pos.
// - Task: delete the node at position pos
// - Output: return the head of the linked list
Node* delete_node(Node* head, int pos);


// - Input: Receive the head "head" of the linked list, an integer x,
//   and a integer pos.
// - Task: Create a node with val equal to x and insert it in position
//   pos of the linked list with head "head". The linked list is
//   0-indexed.
// - Output: return the head of the linked list.
Node* insert_node(Node* head, int x, int pos);


// - Input: Receive the head "head" of the linked list.
// - Task: Print the linked list.
// - Output: None.
void print_linked_list(Node* head);


#endif