#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> vec={2,7,11,15};
    int target=18;
    int n=vec.size();
    int i=0,j=n-1;
    int sum=0;
    while (j > i){
        sum=vec[i]+vec[j];
        if (sum > target){
            j--;
        }
        else if(sum < target){
            i++;
        }
        else {
            cout << i <<" "<< j;
            break;
        }
    }
    return 0;
}