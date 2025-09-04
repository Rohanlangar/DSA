#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    // allocate pointers for rows
    int **A = new int*[n];
    int **B = new int*[n];
    int **RowResult = new int*[n];
    int **ColResult = new int*[n];

    // allocate memory for each row
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        RowResult[i] = new int[n];
        ColResult[i] = new int[n];
    }

    // input A
    cout << "Enter Matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    // input B
    cout << "Enter Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    // Row-wise multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            RowResult[i][j] = 0;
            for (int k = 0; k < n; k++) {
                RowResult[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Column-wise multiplication
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            ColResult[i][j] = 0;
            for (int k = 0; k < n; k++) {
                ColResult[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // print Row-wise result
    cout << "\nRow-wise multiplication result:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << RowResult[i][j] << " ";
        }
        cout << endl;
    }

    // print Column-wise result
    cout << "\nColumn-wise multiplication result:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ColResult[i][j] << " ";
        }
        cout << endl;
    }

    // free memory
    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] RowResult[i];
        delete[] ColResult[i];
    }
    delete[] A;
    delete[] B;
    delete[] RowResult;
    delete[] ColResult;

    return 0;
}
