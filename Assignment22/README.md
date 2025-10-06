# Assignment no : 22
### Title : Implement stack data structure using array with basic operations like push, pop, and display.

#### Theory :
**Stack using Array** is a linear data structure that follows the Last-In-First-Out (LIFO) principle. It uses a fixed-size array to store elements and a top pointer to track the current position.

**Key Components:**
- **Array**: Fixed-size storage for stack elements
- **Top**: Index pointing to the topmost element
- **MAX**: Maximum capacity of the stack

**Basic Operations:**
1. **Push**: Add element to the top of stack
2. **Pop**: Remove element from the top of stack
3. **Top/Peek**: View the top element without removing
4. **isEmpty**: Check if stack is empty
5. **isFull**: Check if stack is full

**Stack States:**
- **Empty Stack**: top = -1
- **Full Stack**: top = MAX - 1
- **Normal State**: 0 ≤ top < MAX - 1

**Error Conditions:**
- **Stack Overflow**: Attempting to push when stack is full
- **Stack Underflow**: Attempting to pop when stack is empty

**Advantages:**
- **Fast Operations**: O(1) time for push/pop
- **Simple Implementation**: Easy to understand and code
- **Memory Efficient**: No extra pointers needed
- **Cache Friendly**: Array elements are contiguous in memory

**Disadvantages:**
- **Fixed Size**: Cannot grow beyond initial capacity
- **Memory Waste**: May allocate more than needed
- **Overflow Risk**: Must check capacity before push

**Applications:**
- Function call management
- Expression evaluation
- Undo operations
- Browser history
- Compiler syntax checking

**Time Complexity:**
- Push: O(1)
- Pop: O(1)
- Top: O(1)
- Display: O(n)

**Space Complexity:** O(MAX) - fixed array size

#### Program :
```cpp
#include <iostream>
using namespace std;

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initStack_rrl(Stack &s) {
    s.top = -1;
}

bool isEmpty_rrl(Stack &s) {
    return s.top == -1;
}

bool isFull_rrl(Stack &s) {
    return s.top == MAX - 1;
}

void push_rrl(Stack &s, int val) {
    if (isFull_rrl(s)) {
        cout << "Stack Overflow! Cannot push " << val << endl;
        return;
    }
    s.top++;
    s.arr[s.top] = val;
    cout << "Pushed " << val << " to stack." << endl;
}

void pop_rrl(Stack &s) {
    if (isEmpty_rrl(s)) {
        cout << "Stack Underflow! Nothing to pop." << endl;
        return;
    }
    int val = s.arr[s.top];
    s.top--;
    cout << "Popped " << val << " from stack." << endl;
}

void display_rrl(Stack &s) {
    if (isEmpty_rrl(s)) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout <<"Stack";
    for (int i = s.top; i >= 0; i--) {
        cout << s.arr[i] << " -> ";
    }
    
}

int main() {
    Stack s;
    initStack_rrl(s);
    int ch, val;

    do {
        cout << "\n***** Stack using Array *****\n";
        cout << "1) Push\n";
        cout << "2) Pop\n";
        cout << "3) Display\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                push_rrl(s, val);
                break;
            case 2:
                pop_rrl(s);
                break;
            case 3:
                display_rrl(s);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (ch != 0);

    return 0;
}
```