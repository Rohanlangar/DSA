# Assignment no : 28
### Title : Implement multiple queue operations using array-based implementation with separate queues for different purposes.

#### Theory :
**Multiple Queues** implementation allows managing several independent queues simultaneously using array-based data structures. Each queue operates independently with its own front and rear pointers.

**Key Features:**
- **Independent Queues** - Each queue has separate front/rear pointers
- **Array-based Implementation** - Fixed size queues using arrays
- **Separate Operations** - Each queue can be manipulated independently
- **Memory Efficient** - Uses contiguous memory allocation

**Queue Structure:**
- **Queue 1**: Independent array with front1, rear1 pointers
- **Queue 2**: Independent array with front2, rear2 pointers
- **Fixed Size**: Each queue has maximum capacity (MAX)

**Operations for Each Queue:**
1. **Enqueue** - Add element to rear of specific queue
2. **Dequeue** - Remove element from front of specific queue
3. **Display** - Show all elements in specific queue
4. **isEmpty** - Check if specific queue is empty
5. **isFull** - Check if specific queue is full

**Array-based Queue Advantages:**
- **Fast Access** - O(1) enqueue/dequeue operations
- **Memory Predictable** - Fixed memory allocation
- **Cache Friendly** - Contiguous memory layout
- **Simple Implementation** - Easy to understand and debug

**Applications:**
- **Process Scheduling** - Different priority queues
- **Print Spooling** - Separate queues for different printers
- **Network Routing** - Different queues for different protocols
- **Task Management** - Separate queues for different task types

**Real-world Scenarios:**
- Hospital departments (Emergency, General, Specialist)
- Bank services (Regular, Premium, Corporate)
- Airport gates (Domestic, International)
- Restaurant orders (Dine-in, Takeaway)

**Time Complexity:**
- Enqueue: O(1)
- Dequeue: O(1)
- Display: O(n)
- isEmpty/isFull: O(1)

**Space Complexity:** O(2×MAX) for two queues

#### Program :
```cpp
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
```