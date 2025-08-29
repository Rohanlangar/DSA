#include <iostream>
using namespace std;

int main(){

    int arr[6]={1,2,2,3,3,3};
    int n =6 ;
    for (int i=0;i<n;i++){
        int cnt=0;

        for (int j=0;j<n;j++){

            if (arr[i]==arr[j]){
                cnt++;
            }
            
        }
        if (cnt % 2 != 0 ){
            cout << arr[i];
        }
    }
    
    return 0;
}