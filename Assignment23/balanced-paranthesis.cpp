#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching_rrl(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced_rrl(const string &expr) {
    stack<char> st;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
            cout << "Push '" << ch << "' onto stack.\n";
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                cout << "Unmatched closing '" << ch << "' found.\n";
                return false;
            }
            char top = st.top();
            st.pop();
            cout << "Pop '" << top << "' from stack.\n";
            if (!isMatching_rrl(top, ch)) {
                cout << "Mismatched pair: '" << top << "' and '" << ch << "'.\n";
                return false;
            }
        }
    }

    if (!st.empty()) {
        cout << "Unmatched opening brackets remain in stack.\n";
        return false;
    }

    return true;
}

int main() {
    string expr;
    cout << "Enter a string of parentheses: ";
    cin >> expr;

    if (isBalanced_rrl(expr)) {
        cout << "The parentheses are balanced.\n";
    } else {
        cout << "The parentheses are NOT balanced.\n";
    }

    return 0;
}
