#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  

    while (t--) {
        int n;
        cin >> n;  

        vector<int> arr(2 * n);  // to store the result for this test case

        // (you’ll fill arr here later)

        int n = 1;
        for(int i=0; i<2*n ; i++)
        {
            if(i + i 
        }


        // print the array for this test case
        for (int i = 0; i < 2 * n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;  // move to next line for next test case
    }

    return 0;
}
