#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n_rrl;
    cout << "Enter number of employees: ";
    cin >> n_rrl;

    int *height_rrl = new int[n_rrl];
    int *weight_rrl = new int[n_rrl];
    float *avg_rrl = new float[n_rrl];

    if (height_rrl == NULL || weight_rrl == NULL || avg_rrl == NULL){
        cout << "Memory not allocatde ";
        return -1;
    }

    cout << "Generated random height and weight:\n";
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        height_rrl[i_rrl] = rand() % 61 + 140; 
        weight_rrl[i_rrl] = rand() % 71 + 40;  
        avg_rrl[i_rrl] = (height_rrl[i_rrl] + weight_rrl[i_rrl]) / 2.0;
        cout << "Emp" << i_rrl + 1 << ": " << height_rrl[i_rrl] << "cm, "
             << weight_rrl[i_rrl] << "kg -> Avg = " << avg_rrl[i_rrl] << endl;
    }

    int pass_rrl = 1;
    cout << "\n--- Selection Sort Passes ---\n";
    for (int i_rrl = 0; i_rrl < n_rrl - 1; i_rrl++) {
        int minIndex_rrl = i_rrl;
        for (int j_rrl = i_rrl + 1; j_rrl < n_rrl; j_rrl++) {
            if (avg_rrl[j_rrl] < avg_rrl[minIndex_rrl]) {
                minIndex_rrl = j_rrl;
            }
        }
        swap(avg_rrl[i_rrl], avg_rrl[minIndex_rrl]);

        cout << "Pass " << pass_rrl++ << ": ";
        for (int k_rrl = 0; k_rrl < n_rrl; k_rrl++) cout << avg_rrl[k_rrl] << " ";
        cout << endl;
    }

    cout << "\nSorted averages:\n";
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) cout << avg_rrl[i_rrl] << " ";

    cout << "\n\nTime Complexity: O(n^2)\n";

    delete[] height_rrl;
    delete[] weight_rrl;
    delete[] avg_rrl;

    return 0;
}
