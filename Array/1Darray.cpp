#include <iostream>
#include <cstdlib>

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* pArr = new int[size];

    if (!pArr) {
        std::cout << "Memory allocation failed.\n";
        return -1;
    }

    for (int i = 0; i < size; ++i) {
        pArr[i] = rand();
    }

    std::cout << "Generated array elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << pArr[i] << " ";
    }

    delete[] pArr;
    pArr = nullptr;

    return 0;
}
