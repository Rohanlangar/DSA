# Assignment Number : 3
### Title :
#### Implement matrix multiplication and analyse its performance using row-major vs column-major order access patterns to understand how memory layout affects cache performance.

##### ----- Algoritham ------ 
1) Start the program.

2) Declare integer pointers for 2D arrays A, B, RowResult, and ColResult.

3) Ask the user to enter the size n of the square matrices.

4) Dynamically allocate memory for all 2D arrays (A, B, RowResult, ColResult).

5) Allocate an array of row pointers first.

6) Then allocate memory for each row.

7) Check if memory allocation was successful.
→ If not, display an error message and exit the program.

8) Input all elements of Matrix A from the user.

9) Input all elements of Matrix B from the user.

9) Perform Row-wise multiplication:
For each row i of A,
For each column j of B,
Initialize RowResult[i][j] = 0.
Multiply corresponding elements and accumulate the sum.

10) Perform Column-wise multiplication:
For each column j of B,
For each row i of A,
Initialize ColResult[i][j] = 0.
Multiply corresponding elements and accumulate the sum.

11) Print the Row-wise result matrix.

12) Print the Column-wise result matrix.

13) Free the dynamically allocated memory for all matrices (A, B, RowResult, ColResult).

14) Set all pointers to NULL (best practice).

15) End the program.

```
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

```
## Output

![alt text](image.png)

https://drive.google.com/file/d/1y670Z4DZ8hQYL8UP0tuhMOqCnl7tmPAw/view?usp=sharing
