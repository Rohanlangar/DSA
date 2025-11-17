#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee_rrl {
    int id_rrl;
    string name_rrl;
    string dept_rrl;
    int salary_rrl;
};

class EmployeeHash_rrl {
public:
    int size_rrl;
    vector<Employee_rrl> table_rrl;
    vector<int> state_rrl;

    EmployeeHash_rrl(int n_rrl = 10) {
        size_rrl = n_rrl;
        table_rrl.assign(size_rrl, Employee_rrl{0,"","",0});
        state_rrl.assign(size_rrl, 0);
    }

    int hash_rrl(int id_rrl) {
        long long sq = 1LL * id_rrl * id_rrl;
        string s = to_string(sq);
        int len = s.length();
        int mid = len / 2;
        int digits = 2;
        int start = max(0, mid - digits / 2);
        int val = stoi(s.substr(start, digits));
        return val % size_rrl;
    }

    bool insert_rrl(Employee_rrl e) {
        int idx = hash_rrl(e.id_rrl);
        int start = idx;

        do {
            if (state_rrl[idx] == 0 || state_rrl[idx] == 2) {
                table_rrl[idx] = e;
                state_rrl[idx] = 1;
                return true;
            }
            idx = (idx + 1) % size_rrl;
        } while (idx != start);

        return false;
    }

    int search_rrl(int id) {
        int idx = hash_rrl(id);
        int start = idx;

        do {
            if (state_rrl[idx] == 0) return -1;
            if (state_rrl[idx] == 1 && table_rrl[idx].id_rrl == id)
                return idx;
            idx = (idx + 1) % size_rrl;
        } while (idx != start);

        return -1;
    }

    bool delete_rrl(int id) {
        int pos = search_rrl(id);
        if (pos == -1) return false;
        state_rrl[pos] = 2;
        table_rrl[pos] = Employee_rrl{0,"","",0};
        return true;
    }

    void display_rrl() {
        cout << "\nIndex\tState\tEmployee\n";
        for (int i = 0; i < size_rrl; i++) {
            cout << i << "\t";
            if (state_rrl[i] == 0)
                cout << "Empty\t-\n";
            else if (state_rrl[i] == 2)
                cout << "Deleted\t-\n";
            else
                cout << "Full\t(" << table_rrl[i].id_rrl << ", "
                     << table_rrl[i].name_rrl << ", "
                     << table_rrl[i].dept_rrl << ", "
                     << table_rrl[i].salary_rrl << ")\n";
        }
    }
};

int main() {
    int size_rrl;
    cout << "Enter table size: ";
    cin >> size_rrl;

    EmployeeHash_rrl ht(size_rrl);

    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nEnter choice: ";
        int ch; cin >> ch;

        if (ch == 1) {
            Employee_rrl e;
            cout << "Enter ID: ";
            cin >> e.id_rrl;
            cout << "Enter Name: ";
            cin >> e.name_rrl;
            cout << "Enter Dept: ";
            cin >> e.dept_rrl;
            cout << "Enter Salary: ";
            cin >> e.salary_rrl;
            if (ht.insert_rrl(e)) cout << "Inserted\n";
            else cout << "Table Full\n";
        }

        else if (ch == 2) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            int pos = ht.search_rrl(id);
            if (pos == -1) cout << "Not found\n";
            else {
                Employee_rrl e = ht.table_rrl[pos];
                cout << "Found at index " << pos << ": "
                     << e.id_rrl << " "
                     << e.name_rrl << " "
                     << e.dept_rrl << " "
                     << e.salary_rrl << "\n";
            }
        }

        else if (ch == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            if (ht.delete_rrl(id)) cout << "Deleted\n";
            else cout << "Not found\n";
        }

        else if (ch == 4) ht.display_rrl();
        else if (ch == 5) break;
        else cout << "Invalid\n";
    }

    return 0;
}
