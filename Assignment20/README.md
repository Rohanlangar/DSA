# Assignment no : 20
### Title : Implement a stock price tracker using stack data structure with linked list implementation for recording and managing stock prices.

#### Theory :
**Stack Data Structure** follows the Last-In-First-Out (LIFO) principle, making it perfect for tracking the most recent stock prices. In this implementation, we use a linked list to create a dynamic stack that can grow and shrink as needed.

**Stack Operations:**
1. **Push** - Add new stock price to the top
2. **Pop** - Remove the most recent price
3. **Top/Peek** - View the latest price without removing
4. **Display** - Show all recorded prices

**LIFO Principle:**
- The last price recorded is the first one to be removed
- Most recent data is always accessible at the top
- Perfect for tracking current/latest stock prices

**Linked List Implementation Advantages:**
- **Dynamic Size** - No fixed size limit
- **Memory Efficient** - Allocates memory as needed
- **No Overflow** - Can grow until system memory is full
- **Easy Implementation** - Simple pointer manipulation

**Applications:**
- Stock price monitoring systems
- Undo operations in applications
- Browser history management
- Function call management in programming

**Real-world Use Case:**
Stock traders need quick access to the most recent prices to make trading decisions. A stack-based system ensures the latest price is always immediately available.

**Time Complexity:**
- Push: O(1)
- Pop: O(1)
- Top: O(1)
- Display: O(n)

**Space Complexity:** O(n) where n is the number of prices stored

#### Program :
```cpp
#include <iostream>
using namespace std;

typedef struct Node {
    int price;
    Node* next;
} Node;

Node* createNode_rrl(int val) {
    Node* node = new Node;
    node->price = val;
    node->next = nullptr;
    return node;
}

class StockStack_rrl {
private:
    Node* top;

public:
    StockStack_rrl() {
        top = nullptr;
    }

    bool isEmpty_rrl() {
        return top == nullptr;
    }

    void record_rrl() {
        int price;
        cout << "Enter price to record: ";
        cin >> price;
        Node* node = createNode_rrl(price);
        node->next = top;
        top = node;
        cout << "Price " << price << " recorded successfully." << endl;
    }

    void remove_rrl() {
        if (isEmpty_rrl()) {
            cout << "Stack is empty. Nothing to remove!" << endl;
            return;
        }
        Node* temp = top;
        int price = temp->price;
        top = top->next;
        delete temp;
        cout << "Removed price: " << price << endl;
    }

    void latest_rrl() {
        if (isEmpty_rrl()) {
            cout << "Stack is empty. No latest price!" << endl;
            return;
        }
        cout << "Latest price: " << top->price << endl;
    }

    void display_rrl() {
        if (isEmpty_rrl()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack (top -> bottom): ";
        while (temp) {
            cout << temp->price << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    StockStack_rrl tracker;
    int ch;

    do {
        cout << "\n***** Stock Price Tracker *****\n";
        cout << "1) Record price\n";
        cout << "2) Remove latest price\n";
        cout << "3) Show latest price\n";
        cout << "4) Display all prices\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                tracker.record_rrl();
                break;
            case 2:
                tracker.remove_rrl();
                break;
            case 3:
                tracker.latest_rrl();
                break;
            case 4:
                tracker.display_rrl();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    } while (ch != 0);

    return 0;
}
```