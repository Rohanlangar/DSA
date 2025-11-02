#include<iostream>
using namespace std;
#include<vector>
#include<stack>

int main()
{
    stack<int>s;
    vector<int>price = {100,80,60,70,60,75,85};

    vector <int> ans;

    for (size_t i = 0 ; i<price.size();i++){
        while(s.size() != 0 && price[s.top()] <= price[i]){
            s.pop();
        }

        if(s.empty()){
            ans.push_back(i+1);
        }else{
            ans.push_back(i-s.top());
        }
        s.push(i);
    }

    for(size_t i = 0 ; i<ans.size() ;i++){
        cout<<ans[i] << " ";
    }

return 0;
}