#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;  // read number of contests

    vector<int> points(n);  

    for (int i = 0; i < n; i++) {
        cin >> points[i];  // read each score
    }

    int amazing_count = 0;
    int max,min;
    min = points[0];
    max = points[0];
    for(int i=1; i<n ; i++)
    {
        if(points[i]<min)
        {
            min = points[i];
            amazing_count++;
        }
        if(points[i]>max)
        {
            max = points[i];
            amazing_count++;
        }
    }

      // placeholder
    cout << amazing_count;  
    return 0;
}
