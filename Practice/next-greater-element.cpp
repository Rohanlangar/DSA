#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include <algorithm>

int main(){

    vector<int> nums = {3,1,0,8,6};
    int n = nums.size();
    stack<int>s;
    vector<int>ans;
    for (int i = 0 ; i<n ; i++){
        while(s.size() != 0 && s.top() > nums[i]){
            s.pop();
        }

        if(s.size()==0){
            ans.push_back(-1);
        }else{
            ans.push_back(s.top());
        }

        s.push(nums[i]);
    }

    for(int i = 0 ; i<ans.size() ;i++){
        cout<<ans[i];
    }

    return 0;
}