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
