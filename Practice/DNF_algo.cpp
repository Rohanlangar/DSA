#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> nums={1,1,0,0,1,2,0,0,2,1};
    int n = nums.size();
    int low=0,high=n-1,mid=0;

    while (mid <= high){
        if (nums[mid] == 0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }else if (nums[mid] == 1){
            mid++;
        }
        else {
            swap(nums[mid],nums[high]);
            high--;
        }
    }

    for( int val : nums){
        cout << val;
    }
    return 0;
}