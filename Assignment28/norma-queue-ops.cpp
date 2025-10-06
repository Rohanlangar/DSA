#include <iostream>
using namespace std;

#define MAX 50

class MultiQueue_rrl {
private:
    int q1[MAX], q2[MAX];
    int front1, rear1, front2, rear2;

public:
    MultiQueue_rrl() {
        front1 = rear1 = -1;
        front2 = rear2 = -1;
    }

    bool isEmpty1_rrl() { return front1 == -1; }
    bool isEmpty2_rrl() { return front2 == -1; }
    bool isFull1_rrl() { return rear1 == MAX - 1; }
    bool isFull2_rrl() { return rear2 == MAX - 1; }

    void enqueue1_rrl() {
        if (isFull1_rrl()) {
            cout << "Queue 1 Overflow!\n";
            return;
        }
        int val;
        cout << "Enter value to add to Queue 1: ";
        cin >> val;
        if (isEmpty1_rrl()) front1 = 0;
        rear1++;
        q1[rear1] = val;
        cout << "Added " << val << " to Queue 1.\n";
    }

    void enqueue2_rrl() {
        if (isFull2_rrl()) {
            cout << "Queue 2 Overflow!\n";
            return;
        }
        int val;
        cout << "Enter value to add to Queue 2: ";
        cin >> val;
        if (isEmpty2_rrl()) front2 = 0;
        rear2++;
        q2[rear2] = val;
        cout << "Added " << val << " to Queue 2.\n";
    }

    void dequeue1_rrl() {
        if (isEmpty1_rrl()) {
            cout << "Queue 1 Underflow!\n";
            return;
        }
        int val = q1[front1];
        if (front1 == rear1) front1 = rear1 = -1;
        else front1++;
        cout << "Removed " << val << " from Queue 1.\n";
    }

    void dequeue2_rrl() {
        if (isEmpty2_rrl()) {
            cout << "Queue 2 Underflow!\n";
            return;
        }
        int val = q2[front2];
        if (front2 == rear2) front2 = rear2 = -1;
        else front2++;
        cout << "Removed " << val << " from Queue 2.\n";
    }

    void display1_rrl() {
        if (isEmpty1_rrl()) {
            cout << "Queue 1 is empty.\n";
            return;
        }
        cout << "Queue 1 elements: ";
        for (int i = front1; i <= rear1; i++) cout << q1[i] << " ";
        cout << endl;
    }

    void display2_rrl() {
        if (isEmpty2_rrl()) {
            cout << "Queue 2 is empty.\n";
            return;
        }
        cout << "Queue 2 elements: ";
        for (int i = front2; i <= rear2; i++) cout << q2[i] << " ";
        cout << endl;
    }
};

int main() {
    MultiQueue_rrl mq;
    int choice;

    do {
        cout << "\n***** Multiple Queues Operations *****\n";
        cout << "1) Add to Queue 1\n";
        cout << "2) Add to Queue 2\n";
        cout << "3) Delete from Queue 1\n";
        cout << "4) Delete from Queue 2\n";
        cout << "5) Display Queue 1\n";
        cout << "6) Display Queue 2\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: mq.enqueue1_rrl(); break;
            case 2: mq.enqueue2_rrl(); break;
            case 3: mq.dequeue1_rrl(); break;
            case 4: mq.dequeue2_rrl(); break;
            case 5: mq.display1_rrl(); break;
            case 6: mq.display2_rrl(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
