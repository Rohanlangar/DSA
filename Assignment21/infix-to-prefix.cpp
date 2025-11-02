#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence_rrl(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator_rrl(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string infixToPostfix_rrl(string infix) {
    stack<char> st;
    string postfix = "";

    cout << "\nStep by step operations:\n";
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
            cout << "Add operand '" << ch << "' to postfix: " << postfix << endl;
        } else if (isOperator_rrl(ch)) {
            while (!st.empty() && precedence_rrl(st.top()) >= precedence_rrl(ch)) {
                cout << "Pop '" << st.top() << "' from stack and add to postfix.\n";
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
            cout << "Push operator '" << ch << "' onto stack.\n";
        }
    }

    while (!st.empty()) {
        cout << "Pop remaining '" << st.top() << "' from stack and add to postfix.\n";
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression (e.g., a-b*c-d/e+f): ";
    cin >> infix;

    string postfix = infixToPostfix_rrl(infix);

    cout << "\nPostfix expression: " << postfix << endl;

    return 0;
}