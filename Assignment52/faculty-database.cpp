#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Faculty_rrl {
    int id_rrl;
    string name_rrl;
    string dept_rrl;
    string designation_rrl;
};

class FacultyHash_rrl {
    public :
    int size_rrl;
    vector<Faculty_rrl> table_rrl;
    vector<int> state_rrl;
    vector<int> next_rrl;

    FacultyHash_rrl(int n_rrl = 10) {
        size_rrl = n_rrl;
        table_rrl.assign(size_rrl, Faculty_rrl{0,"","",""});
        state_rrl.assign(size_rrl, 0);
        next_rrl.assign(size_rrl, -1);
    }

    int hash_rrl(int id_rrl) {
        return id_rrl % size_rrl;
    }

    int findFree_rrl() {
        for (int i = 0; i < size_rrl; i++)
            if (state_rrl[i] == 0) return i;
        return -1;
    }

    bool insert_rrl(Faculty_rrl f) {
        int home = hash_rrl(f.id_rrl);

        if (state_rrl[home] == 0) {
            table_rrl[home] = f;
            state_rrl[home] = 1;
            next_rrl[home] = -1;
            return true;
        }

        int homeExisting = hash_rrl(table_rrl[home].id_rrl);

        if (homeExisting != home) {
            Faculty_rrl temp = table_rrl[home];
            table_rrl[home] = f;

            int freeSlot = findFree_rrl();
            if (freeSlot == -1) return false;

            table_rrl[freeSlot] = temp;
            state_rrl[freeSlot] = 1;

            int tempHome = hash_rrl(temp.id_rrl);
            int cur = tempHome;
            while (next_rrl[cur] != -1) cur = next_rrl[cur];
            next_rrl[cur] = freeSlot;
            next_rrl[freeSlot] = -1;
            return true;
        }

        int freeSlot = findFree_rrl();
        if (freeSlot == -1) return false;

        table_rrl[freeSlot] = f;
        state_rrl[freeSlot] = 1;
        next_rrl[freeSlot] = -1;

        int cur = home;
        while (next_rrl[cur] != -1) cur = next_rrl[cur];
        next_rrl[cur] = freeSlot;

        return true;
    }

    int search_rrl(int id) {
        int home = hash_rrl(id);
        int cur = home;

        while (cur != -1) {
            if (state_rrl[cur] == 1 && table_rrl[cur].id_rrl == id)
                return cur;
            cur = next_rrl[cur];
        }
        return -1;
    }

    bool delete_rrl(int id) {
        int home = hash_rrl(id);
        int cur = home, prev = -1;

        while (cur != -1) {
            if (table_rrl[cur].id_rrl == id && state_rrl[cur] == 1) {
                state_rrl[cur] = 2;
                table_rrl[cur] = Faculty_rrl{0,"","",""};
                if (prev != -1) next_rrl[prev] = next_rrl[cur];
                next_rrl[cur] = -1;
                return true;
            }
            prev = cur;
            cur = next_rrl[cur];
        }
        return false;
    }

    void display_rrl() {
        cout << "\nIndex\tState\tNext\tFaculty\n";
        for (int i = 0; i < size_rrl; i++) {
            cout << i << "\t";
            if (state_rrl[i] == 0) cout << "Empty\t";
            else if (state_rrl[i] == 2) cout << "Del\t";
            else cout << "Full\t";
            cout << next_rrl[i] << "\t";
            if (state_rrl[i] == 1)
                cout << "(" << table_rrl[i].id_rrl << ","
                     << table_rrl[i].name_rrl << ","
                     << table_rrl[i].dept_rrl << ","
                     << table_rrl[i].designation_rrl << ")";
            else cout << "-";
            cout << "\n";
        }
    }
};

int main() {
    int size_rrl;
    cout << "Enter hash table size: ";
    cin >> size_rrl;

    FacultyHash_rrl ht(size_rrl);

    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nEnter choice: ";
        int ch; cin >> ch;

        if (ch == 1) {
            Faculty_rrl f;
            cout << "Enter ID: "; cin >> f.id_rrl;
            cout << "Enter Name: "; cin >> f.name_rrl;
            cout << "Enter Dept: "; cin >> f.dept_rrl;
            cout << "Enter Designation: "; cin >> f.designation_rrl;
            if (ht.insert_rrl(f)) cout << "Inserted\n";
            else cout << "Table Full\n";
        }

        else if (ch == 2) {
            int id; cout << "Enter ID: "; cin >> id;
            int pos = ht.search_rrl(id);
            if (pos == -1) cout << "Not found\n";
            else {
                Faculty_rrl f = ht.table_rrl[pos];
                cout << "Found at index " << pos << ": "
                     << f.id_rrl << " " << f.name_rrl << " "
                     << f.dept_rrl << " " << f.designation_rrl << "\n";
            }
        }

        else if (ch == 3) {
            int id; cout << "Enter ID: "; cin >> id;
            if (ht.delete_rrl(id)) cout << "Deleted\n";
            else cout << "Not found\n";
        }

        else if (ch == 4) ht.display_rrl();
        else if (ch == 5) break;
        else cout << "Invalid choice\n";
    }

    return 0;
}
