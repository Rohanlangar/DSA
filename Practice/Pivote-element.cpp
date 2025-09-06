#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums={2,4,9,3,3};
    int n = nums.size();

    int i =0;
    int j = n-1;
    int presum=nums[i];
    int postsum=nums[j];
    while (i < j){
        if (presum == postsum){
            cout << i+1;
            break;
        }
        else if (presum < postsum ){
            i++;
            presum+=nums[i];
        }else {
            j--;
            postsum+=nums[j];
        }
    }
    return 0;
}

