#include<iostream>
using namespace std;
#include<vector>

bool isValid(vector<int> arr,int n , int m , int maxAllotment){
    int students = 1,pages = 0 ;

    for(int i = 0 ; i < n ; i++){
        if(arr[i] > maxAllotment){
            return false;
        }

        if(pages + arr[i] <= maxAllotment){
            pages+=arr[i];
        }else{
            students++;
            pages=arr[i];
        }
    }

    return students > m ? false : true;
}

int allocateBooks(vector<int> arr,int n ,int m){
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }

    int st = 0 ,end = sum;
    int ans;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isValid(arr,n,m,mid)){
            ans = mid;  
            end = mid-1;
        }else{
            st = mid+1;
        }
    }

    return ans;
}


int main(){
    vector<int> arr = {15,17,20};
    int n = 4 , m = 2;

    cout << allocateBooks(arr,n,m);
    return 0;
}