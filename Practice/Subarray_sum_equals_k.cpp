#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {9,4,20,3,10,5};
    int n = nums.size();
    int target=33;
    int cnt=0;
    for (int i =0 ; i < n ; i++){
        int sum=0;
        sum+=nums[i];
        int j = i+1;
        while (j < n){
            sum+=nums[j];
            if (sum == target){
                cnt++;
                break;
            }else if (sum < target){
                j++;
            }else {
                break;
            }
        }
    }

    cout << cnt;
}