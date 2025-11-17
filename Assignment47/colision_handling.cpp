#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable_rrl {
    int size_rrl;
    vector<list<int>> table_rrl;
public:
    HashTable_rrl(int n_rrl = 10) {
        size_rrl = n_rrl;
        table_rrl.assign(size_rrl, list<int>());
    }
    int hash_rrl(int key_rrl) {
        return key_rrl % size_rrl;
    }
    void insert_rrl(int key_rrl) {
        int idx_rrl = hash_rrl(key_rrl);
        table_rrl[idx_rrl].push_back(key_rrl);
    }
    bool search_rrl(int key_rrl) {
        int idx_rrl = hash_rrl(key_rrl);
        for (int x_rrl : table_rrl[idx_rrl])
            if (x_rrl == key_rrl) return true;
        return false;
    }
    bool delete_rrl(int key_rrl) {
        int idx_rrl = hash_rrl(key_rrl);
        for (auto it_rrl = table_rrl[idx_rrl].begin(); it_rrl != table_rrl[idx_rrl].end(); it_rrl++) {
            if (*it_rrl == key_rrl) {
                table_rrl[idx_rrl].erase(it_rrl);
                return true;
            }
        }
        return false;
    }
    void display_rrl() {
        cout << "Hash Table (Separate Chaining):\n";
        for (int i_rrl = 0; i_rrl < size_rrl; i_rrl++) {
            cout << i_rrl << ": ";
            for (int x_rrl : table_rrl[i_rrl]) cout << x_rrl << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    int choice_rrl, size_rrl;
    cout << "Enter hash table size: ";
    cin >> size_rrl;
    HashTable_rrl ht_rrl(size_rrl);

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice_rrl;

        if (choice_rrl == 1) {
            int key_rrl;
            cout << "Enter key: ";
            cin >> key_rrl;
            ht_rrl.insert_rrl(key_rrl);
            cout << "Inserted\n";
        }
        else if (choice_rrl == 2) {
            int key_rrl;
            cout << "Enter key to search: ";
            cin >> key_rrl;
            if (ht_rrl.search_rrl(key_rrl)) cout << "Key found\n";
            else cout << "Key NOT found\n";
        }
        else if (choice_rrl == 3) {
            int key_rrl;
            cout << "Enter key to delete: ";
            cin >> key_rrl;
            if (ht_rrl.delete_rrl(key_rrl)) cout << "Key deleted\n";
            else cout << "Key NOT found\n";
        }
        else if (choice_rrl == 4) {
            ht_rrl.display_rrl();
        }
        else if (choice_rrl == 5) {
            break;
        }
        else cout << "Invalid choice\n";
    }
    return 0;
}
