#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* prev;
    Node* next;
} Node;

Node* createNode_rrl(int val) {
    Node* node = new Node;
    node->data = val;
    node->prev = nullptr;
    node->next = nullptr;
    return node;
}

Node* createList_rrl() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int ch;
    while (true) {
        cout << "Do you want to insert a value? (1-Yes, 0-No): ";
        cin >> ch;
        if (ch == 0) break;

        int val;
        cout << "Enter value: ";
        cin >> val;

        Node* node = createNode_rrl(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    return head;
}

void bubbleSort_rrl(Node* head) {
    if (!head) return;
    bool swapped;
    Node* ptr;
    Node* last = nullptr;

    do {
        swapped = false;
        ptr = head;
        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

void display_rrl(Node* head) {
    Node* temp = head;
    cout << "Head -> ";
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "****** Doubly Linked List ******" << endl;

    Node* head = createList_rrl();

    cout << "Original List: ";
    display_rrl(head);

    bubbleSort_rrl(head);

    cout << "Sorted List:   ";
    display_rrl(head);

    return 0;
}
