# Assignment No 1 :

## String operation without using buildin function :
### Operations Performed : 
### 1) Length 
### 2) Reverse 
### 3) Concate 

**Code** :
      
```
#include <iostream>
using namespace std;

int length(char str_rrl[]) {
    int i_rrl = 0;
    while (str_rrl[i_rrl] != '\0') {
        i_rrl++;
    }
    return i_rrl;
}

void reverseStr(char str_rrl[]) {
    int n_rrl = length(str_rrl);
    for (int i_rrl = 0; i_rrl < n_rrl / 2; i_rrl++) {
        char temp_rrl = str_rrl[i_rrl];
        str_rrl[i_rrl] = str_rrl[n_rrl - i_rrl - 1];
        str_rrl[n_rrl - i_rrl - 1] = temp_rrl;
    }
}

void concate(char str1_rrl[], char str2_rrl[]) {
    int len1_rrl = length(str1_rrl);
    int len2_rrl = length(str2_rrl);
    int j_rrl = 0;
    for (int i_rrl = len1_rrl; i_rrl < len1_rrl + len2_rrl; i_rrl++) {
        str1_rrl[i_rrl] = str2_rrl[j_rrl];
        j_rrl++;
    }
    str1_rrl[len1_rrl + len2_rrl] = '\0';
}

int main() {
    cout << "Enter a string: ";
    char string1_rrl[100], string2_rrl[100];
    cin >> string1_rrl;

    int choice_rrl;
    cout << "\nMenu:\n";
    cout << "1) Length\n";
    cout << "2) Reverse\n";
    cout << "3) Concatenate\n";
    cout << "0) Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice_rrl;

        switch (choice_rrl) {
        case 1: {
            int len_rrl = length(string1_rrl);
            cout << "Length of given string is: " << len_rrl << endl;
            break;
        }
        case 2: {
            reverseStr(string1_rrl);
            cout << "Reversed string: " << string1_rrl << endl;
            break;
        }
        case 3: {
            cout << "Enter another string to concatenate: ";
            cin >> string2_rrl;
            concate(string1_rrl, string2_rrl);
            cout << "Concatenated string: " << string1_rrl << endl;
            break;
        }
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice_rrl != 0);

    return 0;
}


```

**Output** :

 ![alt text](image.png)
 https://drive.google.com/file/d/100ICh6XQ8hcDA1cTGbvj1SpC3S03h7Py/view?usp=sharing
