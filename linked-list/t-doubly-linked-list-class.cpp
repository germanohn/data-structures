#include <iostream>
#include <string>
#include <limits>
#include "doubly-linked-list-class.h"
using std::string;
using std::cin;
using std::cout;

int main() {
    // create empty doubly linked list
    DoublyLinkedList linkedList;

    // number of insertions
    int n;
    cin >> n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // make n insertions
    for (int i = 0; i < n; i++) {
        string operation;
        std::getline(cin, operation); // stops in the newline character, '\n'

        if (operation == "get") {
            int index;
            cin >> index;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << linkedList.get(index) << "\n";
        } else if (operation == "insert_at_head") {
            int val;
            cin >> val;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            linkedList.insert_at_head(val);
            linkedList.print();
        } else if (operation == "insert_at_tail") {
            int val;
            cin >> val;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            linkedList.insert_at_tail(val);
            linkedList.print();
        } else if (operation == "insert_at_index") {
            int index, val;
            cin >> index >> val;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            linkedList.insert_at_index(index, val);
            linkedList.print();
        } else if (operation == "delete_at_index") {
            int index;
            cin >> index;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            linkedList.delete_at_index(index);
            linkedList.print();
        } else if (operation == "print") {
            linkedList.print();
        } else if (operation == "reverse_print") {
            linkedList.reverse_print();
        } else {
            cout << "error: invalid operation\n";
        }
    }
}