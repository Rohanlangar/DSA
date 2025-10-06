#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() { head = nullptr; }

    void insert(int val_rrl) {
        Node* newNode_rrl = new Node{val_rrl, nullptr};
        if (!head) {
            head = newNode_rrl;
            return;
        }
        Node* temp_rrl = head;
        while (temp_rrl->next) temp_rrl = temp_rrl->next;
        temp_rrl->next = newNode_rrl;
    }

    bool search(int val_rrl) {
        Node* temp_rrl = head;
        while (temp_rrl) {
            if (temp_rrl->data == val_rrl)
                return true;
            temp_rrl = temp_rrl->next;
        }
        return false;
    }

    void display() {
        Node* temp_rrl = head;
        if (!temp_rrl) {
            cout << "Empty Set";
            return;
        }
        while (temp_rrl) {
            cout << temp_rrl->data << " ";
            temp_rrl = temp_rrl->next;
        }
    }
};

LinkedList intersection(LinkedList& A_rrl, LinkedList& B_rrl) {
    LinkedList result_rrl;
    Node* temp_rrl = A_rrl.head;
    while (temp_rrl) {
        if (B_rrl.search(temp_rrl->data))
            result_rrl.insert(temp_rrl->data);
        temp_rrl = temp_rrl->next;
    }
    return result_rrl;
}

LinkedList setUnion(LinkedList& A_rrl, LinkedList& B_rrl) {
    LinkedList result_rrl;
    Node* temp_rrl = A_rrl.head;
    while (temp_rrl) {
        result_rrl.insert(temp_rrl->data);
        temp_rrl = temp_rrl->next;
    }
    temp_rrl = B_rrl.head;
    while (temp_rrl) {
        if (!A_rrl.search(temp_rrl->data))
            result_rrl.insert(temp_rrl->data);
        temp_rrl = temp_rrl->next;
    }
    return result_rrl;
}

LinkedList symmetricDiff(LinkedList& A_rrl, LinkedList& B_rrl) {
    LinkedList result_rrl;
    Node* temp_rrl = A_rrl.head;
    while (temp_rrl) {
        if (!B_rrl.search(temp_rrl->data))
            result_rrl.insert(temp_rrl->data);
        temp_rrl = temp_rrl->next;
    }
    temp_rrl = B_rrl.head;
    while (temp_rrl) {
        if (!A_rrl.search(temp_rrl->data))
            result_rrl.insert(temp_rrl->data);
        temp_rrl = temp_rrl->next;
    }
    return result_rrl;
}

int main() {
    LinkedList A_rrl, B_rrl;
    int nA_rrl, nB_rrl, total_rrl;

    cout << "Enter total number of students in class: ";
    cin >> total_rrl;

    cout << "\nEnter number of students who like Cricket: ";
    cin >> nA_rrl;
    cout << "Enter roll numbers:\n";
    for (int i_rrl = 0; i_rrl < nA_rrl; i_rrl++) {
        int roll_rrl;
        cin >> roll_rrl;
        A_rrl.insert(roll_rrl);
    }

    cout << "\nEnter number of students who like Football: ";
    cin >> nB_rrl;
    cout << "Enter roll numbers:\n";
    for (int i_rrl = 0; i_rrl < nB_rrl; i_rrl++) {
        int roll_rrl;
        cin >> roll_rrl;
        B_rrl.insert(roll_rrl);
    }

    cout << "\nSet A (Cricket): ";
    A_rrl.display();
    cout << "\nSet B (Football): ";
    B_rrl.display();

    LinkedList both_rrl = intersection(A_rrl, B_rrl);
    cout << "\n\nStudents who like BOTH Cricket and Football: ";
    both_rrl.display();

    LinkedList either_rrl = symmetricDiff(A_rrl, B_rrl);
    cout << "\nStudents who like EITHER Cricket or Football but NOT both: ";
    either_rrl.display();

    LinkedList uni_rrl = setUnion(A_rrl, B_rrl);
    int countUnion_rrl = 0;
    Node* temp_rrl = uni_rrl.head;
    while (temp_rrl) {
        countUnion_rrl++;
        temp_rrl = temp_rrl->next;
    }
    int neither_rrl = total_rrl - countUnion_rrl;
    cout << "\nNumber of students who like NEITHER Cricket nor Football: " << neither_rrl << endl;

    return 0;
}
