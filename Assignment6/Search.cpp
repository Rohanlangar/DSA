#include<iostream>
using namespace std;
#include<string>

struct student_rrl{
    int roll_rrl;
    string name_rrl;
};

int main(){ 
    int n_rrl;
    cout << "Enter number of students";
    cin >> n_rrl;

    student_rrl *arr = new student_rrl[n_rrl];

    if (arr==NULL){
        cout << "Memory not allocated";
    }

    cout << "Enter roll number and name"<<endl;
    for (int i = 0 ;i < n_rrl; i++){
        cin >> arr[i].roll_rrl >> arr[i].name_rrl;
    }

    int target_rrl;
    cout << "Enter roll number you want to search"<<endl;
    cin >> target_rrl;
    bool flag_rrl=false;
    for (int i =0 ; i < n_rrl ;i++){
        if (arr[i].roll_rrl == target_rrl){
            cout <<"Student found"<<" "<<"Name of student :"<<arr[i].name_rrl<<endl;
            flag_rrl=true;
        }
    }

    if (flag_rrl == false){
        cout << " Student not found";
    }
    delete[] arr;



    return 0;
}