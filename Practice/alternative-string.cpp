#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1="abcd";
    string s2="pqrstuv";
    int n=s1.length();
    int m=s2.length();
    int k=0;
    string res = "";
    while (k < n && k < m){
        res += s1[k];
        res += s2[k];
        k++;
    }

    while (k < n){
        res += s1[k];
        k++;
    }
    while (k < m){
        res += s2[k];
        k++;
    }

    cout << res;

    return 0;
}