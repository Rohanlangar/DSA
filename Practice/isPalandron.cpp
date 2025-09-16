#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "madam";
    string s2 = "";  

    for (int i = s.size() - 1; i >= 0; i--) {
        s2 += s[i];
    }

    cout << "Reversed string: " << s2 << endl;

    if (s == s2) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
