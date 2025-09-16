#include<iostream>
using namespace std;

int main(){

    int arr[3][3]={
        {1,12,3},
        {9,5,6},
        {7,1,4}
    };
    int csum=0;
    int maxsum=0;
    for (int i =0 ; i < 3 ; i++){
        csum=0;
        for (int j = 0; j < 3;j++){
            csum+=arr[j][i];
        }
        maxsum=max(csum,maxsum);
    }

    cout << maxsum;

    

    return 0;
}