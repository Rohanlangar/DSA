#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix_rrl(const string &expr) {
    stack<int> st;

    cout << "\nStep by step evaluation:\n";

    for (char ch : expr) {
        if (isdigit(ch)) {
            int val = ch - '0';
            st.push(val);
            cout << "Push operand " << val << " onto stack.\n";
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (st.size() < 2) {
                cout << "Invalid expression!\n";
                return -1;
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res;
            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            st.push(res);
            cout << "Pop " << a << " and " << b << ", apply '" << ch << "', push result " << res << " onto stack.\n";
        }
    }

    if (st.size() != 1) {
        cout << "Invalid postfix expression!\n";
        return -1;
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix_rrl(postfix);

    if (result != -1)
        cout << "\nResult of postfix expression: " << result << endl;

    return 0;
}
