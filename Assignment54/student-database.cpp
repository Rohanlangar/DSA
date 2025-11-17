#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student_rrl {
    int roll_rrl;
    string name_rrl;
    string course_rrl;
    int marks_rrl;
};

class StudentHash_rrl {
public:
    int size_rrl;
    vector<Student_rrl> table_rrl;
    vector<int> state_rrl;

    StudentHash_rrl(int n_rrl = 10) {
        size_rrl = n_rrl;
        table_rrl.assign(size_rrl, Student_rrl{0,"","",0});
        state_rrl.assign(size_rrl, 0);
    }

    int hash_rrl(int roll_rrl) {
        return roll_rrl % size_rrl;
    }

    bool insert_rrl(Student_rrl s) {
        int idx = hash_rrl(s.roll_rrl);
        int start = idx;

        do {
            if (state_rrl[idx] == 0 || state_rrl[idx] == 2) {
                table_rrl[idx] = s;
                state_rrl[idx] = 1;
                return true;
            }
            idx = (idx + 1) % size_rrl;
        } while (idx != start);

        return false;
    }

    int search_rrl(int roll) {
        int idx = hash_rrl(roll);
        int start = idx;

        do {
            if (state_rrl[idx] == 0) return -1;
            if (state_rrl[idx] == 1 && table_rrl[idx].roll_rrl == roll)
                return idx;
            idx = (idx + 1) % size_rrl;
        } while (idx != start);

        return -1;
    }

    bool delete_rrl(int roll) {
        int pos = search_rrl(roll);
        if (pos == -1) return false;
        state_rrl[pos] = 2;
        table_rrl[pos] = Student_rrl{0,"","",0};
        return true;
    }

    void display_rrl() {
        cout << "\nIndex\tState\tStudent\n";
        for (int i = 0; i < size_rrl; i++) {
            cout << i << "\t";
            if (state_rrl[i] == 0)
                cout << "Empty\t-\n";
            else if (state_rrl[i] == 2)
                cout << "Deleted\t-\n";
            else
                cout << "Full\t(" 
                     << table_rrl[i].roll_rrl << ", "
                     << table_rrl[i].name_rrl << ", "
                     << table_rrl[i].course_rrl << ", "
                     << table_rrl[i].marks_rrl << ")\n";
        }
    }
};

int main() {
    int size_rrl;
    cout << "Enter hash table size: ";
    cin >> size_rrl;

    StudentHash_rrl ht(size_rrl);

    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nEnter choice: ";
        int ch; cin >> ch;

        if (ch == 1) {
            Student_rrl s;
            cout << "Enter Roll No: "; cin >> s.roll_rrl;
            cout << "Enter Name: "; cin >> s.name_rrl;
            cout << "Enter Course: "; cin >> s.course_rrl;
            cout << "Enter Marks: "; cin >> s.marks_rrl;
            if (ht.insert_rrl(s)) cout << "Inserted\n";
            else cout << "Table Full\n";
        }

        else if (ch == 2) {
            int roll;
            cout << "Enter Roll No: ";
            cin >> roll;
            int pos = ht.search_rrl(roll);
            if (pos == -1)
                cout << "Not found\n";
            else {
                Student_rrl s = ht.table_rrl[pos];
                cout << "Found at index " << pos << ": "
                     << s.roll_rrl << " " << s.name_rrl << " "
                     << s.course_rrl << " " << s.marks_rrl << "\n";
            }
        }

        else if (ch == 3) {
            int roll;
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            if (ht.delete_rrl(roll)) cout << "Deleted\n";
            else cout << "Not found\n";
        }

        else if (ch == 4) ht.display_rrl();
        else if (ch == 5) break;
        else cout << "Invalid\n";
    }

    return 0;
}
