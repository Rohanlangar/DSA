# Assignment no : 24
### Title : Implement a program to evaluate postfix expressions using stack data structure with step-by-step visualization.

#### Theory :
**Postfix Expression Evaluation** is a fundamental application of stack data structure that evaluates mathematical expressions written in postfix notation (also known as Reverse Polish Notation).

**Postfix Notation:**
- Operators come after their operands
- No parentheses needed
- Natural evaluation order from left to right
- Example: "3 4 +" means "3 + 4"

**Algorithm Steps:**
1. Scan the postfix expression from left to right
2. If operand: Push onto stack
3. If operator:
   - Pop two operands from stack (second operand first, then first operand)
   - Apply the operator
   - Push the result back onto stack
4. Final result is the only element left in stack

**Stack Operations:**
- **Push**: Store operands temporarily
- **Pop**: Retrieve operands for calculation
- **LIFO**: Ensures correct operand order

**Evaluation Example:**
Expression: "5 3 + 2 *"
1. Push 5, Push 3
2. Pop 3, Pop 5, Calculate 5+3=8, Push 8
3. Push 2
4. Pop 2, Pop 8, Calculate 8*2=16, Push 16
5. Result: 16

**Time Complexity:** O(n) where n is the length of expression

#### Program :
```cpp
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
```

![alt text](image.png)

https://drive.google.com/file/d/18tYwoY5WQ9hMJuMKnV0-xU5R7uLlMOqc/view?usp=drive_link