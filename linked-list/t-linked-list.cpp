#include <iostream>
#include <string>
#include <limits>
#include "linked-list.h"
using std::string;
using std::cin;
using std::cout;

int main() {
    // create empty linked list
    Node* head = nullptr;

    // number of insertions
    int n;
    cin >> n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // make n insertions
    for (int i = 0; i < n; i++) {
        string operation;
        std::getline(cin, operation); // stops in the newline character, '\n'
        cout << "operation " << operation << "\n";
        if (operation == "insert") {
            int x, pos;
            cin >> x >> pos;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            head = insert_node(head, x, pos);
            print_linked_list(head);
        } else if (operation == "delete") {
            int pos;
            cin >> pos;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            head = delete_node(head, pos);
            print_linked_list(head);
        } else if (operation == "reverse") {
            head = reverse_linked_list(head);
            print_linked_list(head);
        } else if (operation == "reverse recursively") {
            head = reverse_linked_list_recursively(head);
            print_linked_list(head);
        } else if (operation == "other reverse recursively") {
            head = other_reverse_recursively(head);
            print_linked_list(head);
        } else {
            cout << "error: invalid operation\n";
        }
    }
}