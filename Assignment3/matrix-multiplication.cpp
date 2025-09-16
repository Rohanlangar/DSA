#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int main() {
    int n_rrl;
    cout << "Enter size of matrix: ";
    cin >> n_rrl;

    srand(time(0)); 

    int **A_rrl = new int*[n_rrl];
    int **B_rrl = new int*[n_rrl];
    int **RowResult_rrl = new int*[n_rrl];
    int **ColResult_rrl = new int*[n_rrl];

    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        A_rrl[i_rrl] = new int[n_rrl];
        B_rrl[i_rrl] = new int[n_rrl];
        RowResult_rrl[i_rrl] = new int[n_rrl];
        ColResult_rrl[i_rrl] = new int[n_rrl];
    }

    cout << "Matrix A_rrl (random values):\n";
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        for (int j_rrl = 0; j_rrl < n_rrl; j_rrl++) {
            A_rrl[i_rrl][j_rrl] = rand() % 10; 
            cout << A_rrl[i_rrl][j_rrl] << " ";
        }
        cout << endl;
    }

    // input B_rrl with random numbers
    cout << "\nMatrix B_rrl (random values):\n";
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        for (int j_rrl = 0; j_rrl < n_rrl; j_rrl++) {
            B_rrl[i_rrl][j_rrl] = rand() % 10; 
            cout << B_rrl[i_rrl][j_rrl] << " ";
        }
        cout << endl;
    }

    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        for (int j_rrl = 0; j_rrl < n_rrl; j_rrl++) {
            RowResult_rrl[i_rrl][j_rrl] = 0;
            for (int k_rrl = 0; k_rrl < n_rrl; k_rrl++) {
                RowResult_rrl[i_rrl][j_rrl] += A_rrl[i_rrl][k_rrl] * B_rrl[k_rrl][j_rrl];
            }
        }
    }

    for (int j_rrl = 0; j_rrl < n_rrl; j_rrl++) {
        for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
            ColResult_rrl[i_rrl][j_rrl] = 0;
            for (int k_rrl = 0; k_rrl < n_rrl; k_rrl++) {
                ColResult_rrl[i_rrl][j_rrl] += A_rrl[i_rrl][k_rrl] * B_rrl[k_rrl][j_rrl];
            }
        }
    }

    cout << "\nRow-wise multiplication result:\n";
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        for (int j_rrl = 0; j_rrl < n_rrl; j_rrl++) {
            cout << RowResult_rrl[i_rrl][j_rrl] << " ";
        }
        cout << endl;
    }

    cout << "\nColumn-wise multiplication result:\n";
    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        for (int j_rrl = 0; j_rrl < n_rrl; j_rrl++) {
            cout << ColResult_rrl[i_rrl][j_rrl] << " ";
        }
        cout << endl;
    }

    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        delete[] A_rrl[i_rrl];
        delete[] B_rrl[i_rrl];
        delete[] RowResult_rrl[i_rrl];
        delete[] ColResult_rrl[i_rrl];
    }
    delete[] A_rrl;
    delete[] B_rrl;
    delete[] RowResult_rrl;
    delete[] ColResult_rrl;

    return 0;
}
