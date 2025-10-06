#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
    string patientName;
    string doctorName;
    Node* next;
} Node;

Node* createNode_rrl(string patient, string doctor) {
    Node* node = new Node;
    node->patientName = patient;
    node->doctorName = doctor;
    node->next = nullptr;
    return node;
}

class PatientQueue_rrl {
private:
    Node* front;
    Node* rear;

public:
    PatientQueue_rrl() {
        front = rear = nullptr;
    }

    bool isEmpty_rrl() {
        return front == nullptr;
    }

    void enqueue_rrl() {
        string patient, doctor;
        cout << "Enter patient name: ";
        cin >> patient;
        cout << "Enter doctor name: ";
        cin >> doctor;

        Node* node = createNode_rrl(patient, doctor);
        if (rear == nullptr) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        cout << "Patient " << patient << " assigned to Dr. " << doctor << " and added to queue.\n";
    }

    void dequeue_rrl() {
        if (isEmpty_rrl()) {
            cout << "No patients in queue.\n";
            return;
        }
        Node* temp = front;
        cout << "Patient " << temp->patientName << " is being attended by Dr. " << temp->doctorName << ".\n";
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void display_rrl() {
        if (isEmpty_rrl()) {
            cout << "No patients in queue.\n";
            return;
        }
        Node* temp = front;
        cout << "Patients in queue (front -> rear):\n";
        while (temp) {
            cout << temp->patientName << " -> Dr." << temp->doctorName << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PatientQueue_rrl queue;
    int ch;

    do {
        cout << "\n***** Medical Clinic Patient Tracker *****\n";
        cout << "1) Add Patient\n";
        cout << "2) Attend Patient\n";
        cout << "3) Display Queue\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                queue.enqueue_rrl();
                break;
            case 2:
                queue.dequeue_rrl();
                break;
            case 3:
                queue.display_rrl();
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
