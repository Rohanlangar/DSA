#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Student_rrl {
    int roll_rrl;
    string name_rrl;
    string course_rrl;
    double cgpa_rrl;
    int year_rrl;
    string email_rrl;
    int placed_company_rrl;
    int state_rrl; 
    Student_rrl(): roll_rrl(0), name_rrl(""), course_rrl(""), cgpa_rrl(0.0), year_rrl(0), email_rrl(""), placed_company_rrl(-1), state_rrl(0) {}
};

bool isPrime_rrl(int n_rrl) {
    if (n_rrl <= 1) return false;
    if (n_rrl <= 3) return true;
    if (n_rrl % 2 == 0) return false;
    for (int i_rrl = 3; i_rrl * i_rrl <= n_rrl; i_rrl += 2)
        if (n_rrl % i_rrl == 0) return false;
    return true;
}

int nextPrime_rrl(int n_rrl) {
    int p_rrl = n_rrl;
    while (!isPrime_rrl(p_rrl)) p_rrl++;
    return p_rrl;
}

class StudentHash_rrl {
    public:
    int capacity_rrl;
    int size_used_rrl;
    vector<Student_rrl> table_rrl;

    int h1_rrl(int key_rrl) { return key_rrl % capacity_rrl; }
    int h2_rrl(int key_rrl) { return 1 + (key_rrl % (capacity_rrl - 2)); }

    void rehash_rrl() {
        int newCap_rrl = nextPrime_rrl(capacity_rrl * 2);
        vector<Student_rrl> old_rrl = table_rrl;
        table_rrl.assign(newCap_rrl, Student_rrl());
        int oldCap_rrl = capacity_rrl;
        capacity_rrl = newCap_rrl;
        size_used_rrl = 0;
        for (int i_rrl = 0; i_rrl < oldCap_rrl; i_rrl++) {
            if (old_rrl[i_rrl].state_rrl == 1) {
                insert_rrl(old_rrl[i_rrl], false);
            }
        }
    }

public:
    StudentHash_rrl(int cap_rrl = 11) {
        capacity_rrl = nextPrime_rrl(cap_rrl);
        table_rrl.assign(capacity_rrl, Student_rrl());
        size_used_rrl = 0;
    }

    bool insert_rrl(const Student_rrl &s_rrl, bool checkResize_rrl = true) {
        if (checkResize_rrl) {
            double load_rrl = (double)size_used_rrl / capacity_rrl;
            if (load_rrl > 0.6) rehash_rrl();
        }
        int key_rrl = s_rrl.roll_rrl;
        int i_rrl = 0;
        int idx_rrl = (h1_rrl(key_rrl) + i_rrl * h2_rrl(key_rrl)) % capacity_rrl;
        int firstDeleted_rrl = -1;
        while (i_rrl < capacity_rrl) {
            if (table_rrl[idx_rrl].state_rrl == 0) {
                if (firstDeleted_rrl != -1) idx_rrl = firstDeleted_rrl;
                table_rrl[idx_rrl] = s_rrl;
                table_rrl[idx_rrl].state_rrl = 1;
                size_used_rrl++;
                return true;
            } else if (table_rrl[idx_rrl].state_rrl == 2) {
                if (firstDeleted_rrl == -1) firstDeleted_rrl = idx_rrl;
            } else if (table_rrl[idx_rrl].state_rrl == 1 && table_rrl[idx_rrl].roll_rrl == key_rrl) {
                return false;
            }
            i_rrl++;
            idx_rrl = (h1_rrl(key_rrl) + i_rrl * h2_rrl(key_rrl)) % capacity_rrl;
        }
        if (firstDeleted_rrl != -1) {
            table_rrl[firstDeleted_rrl] = s_rrl;
            table_rrl[firstDeleted_rrl].state_rrl = 1;
            size_used_rrl++;
            return true;
        }
        return false;
    }

    int search_rrl(int roll_rrl) {
        int key_rrl = roll_rrl;
        int i_rrl = 0;
        int idx_rrl = (h1_rrl(key_rrl) + i_rrl * h2_rrl(key_rrl)) % capacity_rrl;
        while (i_rrl < capacity_rrl) {
            if (table_rrl[idx_rrl].state_rrl == 0) return -1;
            if (table_rrl[idx_rrl].state_rrl == 1 && table_rrl[idx_rrl].roll_rrl == key_rrl) return idx_rrl;
            i_rrl++;
            idx_rrl = (h1_rrl(key_rrl) + i_rrl * h2_rrl(key_rrl)) % capacity_rrl;
        }
        return -1;
    }

    bool remove_rrl(int roll_rrl) {
        int pos_rrl = search_rrl(roll_rrl);
        if (pos_rrl == -1) return false;
        table_rrl[pos_rrl] = Student_rrl();
        table_rrl[pos_rrl].state_rrl = 2;
        size_used_rrl--;
        return true;
    }

    void display_rrl() {
        cout << "\nIdx\tState\tRoll\tName\tCourse\tCGPA\tYear\tEmail\n";
        for (int i_rrl = 0; i_rrl < capacity_rrl; i_rrl++) {
            cout << i_rrl << "\t";
            if (table_rrl[i_rrl].state_rrl == 0) cout << "Empty\t-\n";
            else if (table_rrl[i_rrl].state_rrl == 2) cout << "Deleted\t-\n";
            else {
                cout << "Full\t" << table_rrl[i_rrl].roll_rrl << "\t" << table_rrl[i_rrl].name_rrl << "\t"
                     << table_rrl[i_rrl].course_rrl << "\t" << table_rrl[i_rrl].cgpa_rrl << "\t"
                     << table_rrl[i_rrl].year_rrl << "\t" << table_rrl[i_rrl].email_rrl << "\n";
            }
        }
        cout << "Capacity: " << capacity_rrl << "  Size: " << size_used_rrl << "\n";
    }

    void autofill_rrl() {
        Student_rrl s1; s1.roll_rrl = 101; s1.name_rrl = "Rohan"; s1.course_rrl = "CSE"; s1.cgpa_rrl = 8.5; s1.year_rrl = 2022; s1.email_rrl = "rohan@uni";
        Student_rrl s2; s2.roll_rrl = 202; s2.name_rrl = "Aman"; s2.course_rrl = "ECE"; s2.cgpa_rrl = 7.8; s2.year_rrl = 2021; s2.email_rrl = "aman@uni";
        Student_rrl s3; s3.roll_rrl = 303; s3.name_rrl = "Priya"; s3.course_rrl = "IT"; s3.cgpa_rrl = 9.0; s3.year_rrl = 2022; s3.email_rrl = "priya@uni";
        insert_rrl(s1); insert_rrl(s2); insert_rrl(s3);
    }
};

int main() {
    int cap_rrl;
    cout << "Enter initial table capacity: ";
    cin >> cap_rrl;
    StudentHash_rrl ht_rrl(cap_rrl);

    while (true) {
        cout << "\n1.Insert 2.Search 3.Delete 4.Display 5.AutoFill 6.Exit\nEnter choice: ";
        int ch_rrl; cin >> ch_rrl;
        if (ch_rrl == 1) {
            Student_rrl s_rrl;
            cout << "Roll: "; cin >> s_rrl.roll_rrl;
            cout << "Name: "; cin >> s_rrl.name_rrl;
            cout << "Course: "; cin >> s_rrl.course_rrl;
            cout << "CGPA: "; cin >> s_rrl.cgpa_rrl;
            cout << "Year: "; cin >> s_rrl.year_rrl;
            cout << "Email: "; cin >> s_rrl.email_rrl;
            if (ht_rrl.insert_rrl(s_rrl)) cout << "Inserted\n"; else cout << "Insert failed\n";
        } else if (ch_rrl == 2) {
            int r_rrl; cout << "Enter roll to search: "; cin >> r_rrl;
            int pos_rrl = ht_rrl.search_rrl(r_rrl);
            if (pos_rrl == -1) cout << "Not found\n";
            else {
                Student_rrl s_rrl = ht_rrl.table_rrl[pos_rrl];
                cout << "Found at idx " << pos_rrl << ": " << s_rrl.roll_rrl << " " << s_rrl.name_rrl << "\n";
            }
        } else if (ch_rrl == 3) {
            int r_rrl; cout << "Enter roll to delete: "; cin >> r_rrl;
            if (ht_rrl.remove_rrl(r_rrl)) cout << "Deleted\n"; else cout << "Not found\n";
        } else if (ch_rrl == 4) ht_rrl.display_rrl();
        else if (ch_rrl == 5) { ht_rrl.autofill_rrl(); cout << "Autofill done\n"; }
        else if (ch_rrl == 6) break;
        else cout << "Invalid\n";
    }
    return 0;
}