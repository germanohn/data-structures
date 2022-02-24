#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
    vector<int> hash_set;
public:
    MyHashSet(int n) {
        hash_set.assign(n, -1);
    }

    void add(int key) {
        hash_set[key] = 1;
    }

    void remove(int key) {
        hash_set[key] = -1;
    }

    bool contains(int key) {
        if (hash_set[key] == 1) {
            return true;
        }
        return false;
    }
};

int main() {
    int n;
    scanf(" %d", &n);

    MyHashSet obj(n);

    int q;
    scanf(" %d", &q);
    while (q--) {
        string command;
        int key;
        cin >> command >> key;

        if (command == "add") {
            obj.add(key);
        } else if (command == "remove") {
            obj.remove(key);
        } else {
            if (obj.contains(key)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
}