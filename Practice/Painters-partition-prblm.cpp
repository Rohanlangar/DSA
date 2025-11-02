#include<iostream>
using namespace std;
#include<vector>

bool isValid(vector<int> arr,int n , int m ,int mid){
    int painters = 1 , time = 0;

    for(int i = 0 ; i < n ;i++){
        if(arr[i] > mid){
            return false;
        }

        if(time + arr[i] <= mid){
            time+=arr[i];
        }else{
            painters++;
            time = arr[i];
        }
    }

    return painters > m ? false : true;
}

int paintersPartition(vector<int> arr, int n ,int m){
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }

    int st = 0 ,end = sum;
    int ans;
    while(st<=end){
        int mid = st+(end-st)/2;

        if(isValid(arr,n,m,mid)){
            ans = mid;
            end = mid-1;
        }else{
            st=mid+1;
        }
    }

    return ans;
}


int main(){
    vector<int> arr = {40,30,10,20};
    int n = 4,m=2;

    cout<<paintersPartition(arr,n,m);
    return 0;
}