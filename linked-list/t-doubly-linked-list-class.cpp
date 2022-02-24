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
        cout << "operation " << operation << "\n";

        if (operation == "insert at head") {
            int val;
            cin >> val;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            linkedList.InsertAtHead(val);
            linkedList.Print();
        } else if (operation == "insert at tail") {
            int val;
            cin >> val;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            linkedList.InsertAtTail(val);
            linkedList.Print();
        } else if (operation == "reverse print") {
            linkedList.ReversePrint();
        } else {
            cout << "error: invalid operation\n";
        }
    }
}