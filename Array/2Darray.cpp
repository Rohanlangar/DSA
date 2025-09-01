#include <iostream>

int main() {
    int** pArr = nullptr;
    int rows, cols;

    std::cout << "Enter the Number of Rows: ";
    std::cin >> rows;

    std::cout << "Enter the Number of Columns: ";
    std::cin >> cols;

    pArr = new int*[rows];
    if (!pArr) {
        std::cout << "Memory allocation failed for row pointers.\n";
        return -1;
    }

    for (int i = 0; i < rows; i++) {
        pArr[i] = new int[cols];
        if (!pArr[i]) {
            std::cout << "Memory allocation failed for row " << i << ".\n";
            for (int j = 0; j < i; j++)
                delete[] pArr[j];
            delete[] pArr;
            pArr = nullptr;
            return -2;
        }
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            pArr[i][j] = (i * j) + 100;

    std::cout << "\nGenerated 2D Array (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << pArr[i][j] << "\t";
        std::cout << "\n";
    }

    for (int i = 0; i < rows; i++)
        delete[] pArr[i];
    delete[] pArr;
    pArr = nullptr;

    return 0;
}
