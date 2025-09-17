#include <iostream>
#include <string>
using namespace std;

struct Student {
    string student_name;
    int student_roll_no;
    float total_marks;
};

void swapStudents(Student &a_rrl, Student &b_rrl, int &swapCount_rrl) {
    Student temp_rrl = a_rrl;
    a_rrl = b_rrl;
    b_rrl = temp_rrl;
    swapCount_rrl++;
}

int partition(Student arr_rrl[], int low_rrl, int high_rrl, int &swapCount_rrl) {
    int pivot_rrl = arr_rrl[high_rrl].student_roll_no;  
    int i_rrl = low_rrl - 1;

    for (int j_rrl = low_rrl; j_rrl < high_rrl; j_rrl++) {
        if (arr_rrl[j_rrl].student_roll_no < pivot_rrl) {
            i_rrl++;
            swapStudents(arr_rrl[i_rrl], arr_rrl[j_rrl], swapCount_rrl);
        }
    }
    swapStudents(arr_rrl[i_rrl + 1], arr_rrl[high_rrl], swapCount_rrl);
    return i_rrl + 1;
}

void quickSort(Student arr_rrl[], int low_rrl, int high_rrl, int &swapCount_rrl) {
    if (low_rrl < high_rrl) {
        int pi_rrl = partition(arr_rrl, low_rrl, high_rrl, swapCount_rrl);
        quickSort(arr_rrl, low_rrl, pi_rrl - 1, swapCount_rrl);
        quickSort(arr_rrl, pi_rrl + 1, high_rrl, swapCount_rrl);
    }
}

void displayStudents(Student arr_rrl[], int n_rrl) {
    cout << "\nRoll No\tName\t\tTotal Marks\n";
    cout << "----------------------------------\n";
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        cout << arr_rrl[i_rrl].student_roll_no << "\t"
             << arr_rrl[i_rrl].student_name << "\t\t"
             << arr_rrl[i_rrl].total_marks << "\n";
    }
}

int main() {
    int n_rrl;
    cout << "Enter number of students: ";
    cin >> n_rrl;

    Student *arr_rrl = new Student[n_rrl];

    cout << "Enter student details (Name RollNo Marks):\n";
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        cin >> arr_rrl[i_rrl].student_name >> arr_rrl[i_rrl].student_roll_no >> arr_rrl[i_rrl].total_marks;
    }

    int quickSwapCount_rrl = 0;
    quickSort(arr_rrl, 0, n_rrl - 1, quickSwapCount_rrl);

    cout << "\n--- Quick Sort Result ---";
    displayStudents(arr_rrl, n_rrl);
    cout << "Total swaps (Quick Sort): " << quickSwapCount_rrl << endl;

    delete[] arr_rrl;
    return 0;
}
