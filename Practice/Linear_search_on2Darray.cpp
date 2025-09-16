#include<iostream>
using namespace std;

int main(){

    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int target= 9;
    bool flag=false;
    for (int i =0 ; i < 3 ; i++){
        for (int j = 0; j < 3;j++){
            if (arr[i][j] == target){
                cout << "Element found at :" << i <<" "<< j;
                flag=true;
                break;
            }else{
                flag=false;
            }
        }
    }

    if (!flag){
        cout << "Element not found";
    }

    return 0;
}