# Practice 

## Max-Min Pairs
## Code :

```
#include <iostream>
using namespace std;
int main(){

    int arr[8]={1,2,3,4,5,6,7,8};
    int n=8;
    for (int i=0;i<n;i++){
        cout<<arr[i];
    }
    for (int i=0;i<n;i+=2){
        int temp=arr[i];

        for(int j=n-1;j>=n-1;j--){
            arr[i]=arr[j];
        }

        for (int k=n-2;k>=i+1;k--){
            arr[k+1]=arr[k];
        }

      arr[i+1]=temp;
    }
    cout<<"Max-min pair";
    for (int i=0;i<n;i++){
        cout << arr[i];
    }

    return 0;
}
```

## Output :

![alt text](image.png)