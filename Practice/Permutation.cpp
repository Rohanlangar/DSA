#include<iostream>
using namespace std;
#include<string>
#include<vector>

void getper(string &s,int ind){
    if(ind == s.size()){
        cout<<s<<" ";
        return ;
    }

    for(int i = ind ; i < s.size() ; i++){
        swap(s[ind],s[i]);
        getper(s,ind+1);
        swap(s[ind],s[i]);
    }
}

int main(){

    string s = "abc";
    getper(s,0);

    return 0;
}