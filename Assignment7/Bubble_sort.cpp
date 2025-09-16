#include<iostream>
#include<string>
using namespace std;

struct student_rrl
{
    int roll_no_rrl;
    string name_rrl;
    int marks_rrl;
};

int main(){
    int n_rrl;
    cout << " Enter number of student";
    cin >> n_rrl;

    student_rrl *arr_rrl = new student_rrl[n_rrl];

    if (arr_rrl == NULL){
        cout << "Memory not allocated";
    }

    cout << "Enter student details (roll,name,marks) :" << endl;
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++){
        cin >> arr_rrl[i_rrl].roll_no_rrl >> arr_rrl[i_rrl].name_rrl >> arr_rrl[i_rrl].marks_rrl;
    }

    cout << "Student Details (before sort) :" << endl;
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++){
        cout <<"Roll number :"<<arr_rrl[i_rrl].roll_no_rrl <<" "<< "Name :" << arr_rrl[i_rrl].name_rrl <<" "<< "Marks : " << arr_rrl[i_rrl].marks_rrl << endl;
    }

    for(int i_rrl = 0; i_rrl < n_rrl; i_rrl++){
        for (int j_rrl = i_rrl + 1; j_rrl < n_rrl; j_rrl++){
            if (arr_rrl[i_rrl].roll_no_rrl > arr_rrl[j_rrl].roll_no_rrl){
                student_rrl temp_rrl = arr_rrl[i_rrl];
                arr_rrl[i_rrl] = arr_rrl[j_rrl];
                arr_rrl[j_rrl] = temp_rrl;
            }
        }
    }

    cout << "Student Details (after sort) :" << endl;
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++){
        cout <<"Roll number :"<<arr_rrl[i_rrl].roll_no_rrl <<" "<< "Name :" << arr_rrl[i_rrl].name_rrl <<" "<< "Marks : " << arr_rrl[i_rrl].marks_rrl << endl;
    }

    return 0;
}
