#include <iostream>
#include <string>
#include <limits>
#include "linked-list-class.cpp"
using std::string;
using std::cin;
using std::cout;

int main() {
    // create empty linked list
    MyLinkedList linkedList;

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
            linkedList.addAtIndex(pos, x);
            linkedList.print();
        } else if (operation == "delete") {
            int pos;
            cin >> pos;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            linkedList.deleteAtIndex(pos);
            linkedList.print();
        } else if (operation == "get") {
            int pos;
            cin >> pos;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int val = linkedList.get(pos);
            cout << val << "\n";
        } else {
            cout << "error: invalid operation\n";
        }
    }
}