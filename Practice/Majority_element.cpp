#include <iostream>
using namespace std;

int main(){
    int arr[6]={1,2,3,3,3,3};
    int n=6;
    int cnt=0;
    for (int i =0 ;i < n ;i++){
        cnt=0;
        for ( int j =0 ; j < n; j++ ){
            if (arr[i] == arr[j]){
                cnt+=1;
            } 
        }
        if (cnt > n/2){
                cout << arr[i];
                break;
            }   
    }
}