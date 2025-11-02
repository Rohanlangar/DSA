#include <iostream>
#include <string>
using namespace std;

class PizzaQueue_rrl {
private:
    int front, rear, maxSize;
    string* orders;

public:
    PizzaQueue_rrl(int n) {
        maxSize = n;
        orders = new string[maxSize];
        front = rear = -1;
    }

    ~PizzaQueue_rrl() {
        delete[] orders;
    }

    bool isEmpty_rrl() {
        return front == -1;
    }

    bool isFull_rrl() {
        return ((rear + 1) % maxSize == front);
    }

    void placeOrder_rrl() {
        if (isFull_rrl()) {
            cout << "Order queue is full! Cannot accept new orders.\n";
            return;
        }
        string orderName;
        cout << "Enter order details (e.g., Pizza type): ";
        cin >> orderName;

        if (isEmpty_rrl()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }
        orders[rear] = orderName;
        cout << "Order '" << orderName << "' placed successfully.\n";
    }

    void serveOrder_rrl() {
        if (isEmpty_rrl()) {
            cout << "No orders to serve.\n";
            return;
        }
        cout << "Serving order: " << orders[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
    }

    void displayOrders_rrl() {
        if (isEmpty_rrl()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending orders: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear) break;
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter maximum number of orders the pizza parlour can accept: ";
    cin >> n;

    PizzaQueue_rrl pq(n);
    int ch;

    do {
        cout << "\n***** Pizza Parlour Order System *****\n";
        cout << "1) Place Order\n";
        cout << "2) Serve Order\n";
        cout << "3) Display Pending Orders\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                pq.placeOrder_rrl();
                break;
            case 2:
                pq.serveOrder_rrl();
                break;
            case 3:
                pq.displayOrders_rrl();
                break;
            case 0:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(ch != 0);

    return 0;
}