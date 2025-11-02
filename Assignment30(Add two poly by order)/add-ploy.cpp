#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

Node* createNode(int coeff, int exp) {
    Node* node = new Node;
    node->coeff = coeff;
    node->exp = exp;
    node->next = nullptr;
    return node;
}

Node* createPoly() {
    int n;
    cout << "\nEnter number of terms in polynomial: ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "\nEnter each term in descending order of exponents.\n";
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        cout << "Term " << i + 1 << ":\n";
        cout << "  Coefficient: ";
        cin >> coeff;
        cout << "  Exponent: ";
        cin >> exp;

        Node* node = createNode(coeff, exp);
        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void display(Node* head) {
    if (!head) {
        cout << "0";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->exp;
        if (temp->next && temp->next->coeff >= 0)
            cout << " + ";
        else if (temp->next)
            cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* addPoly(Node* p1, Node* p2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (p1 && p2) {
        Node* node = nullptr;

        if (p1->exp > p2->exp) {
            node = createNode(p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            node = createNode(p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                node = createNode(sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }

        if (node) {
            if (!result)
                result = tail = node;
            else {
                tail->next = node;
                tail = node;
            }
        }
    }

    while (p1) {
        Node* node = createNode(p1->coeff, p1->exp);
        if (!result)
            result = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
        p1 = p1->next;
    }
    while (p2) {
        Node* node = createNode(p2->coeff, p2->exp);
        if (!result)
            result = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
        p2 = p2->next;
    }

    return result;
}

int main() {
    cout << "=== Polynomial Addition Using Singly Linked List ===\n";

    cout << "\nEnter first polynomial:\n";
    Node* poly1 = createPoly();

    cout << "\nEnter second polynomial:\n";
    Node* poly2 = createPoly();

    cout << "\nFirst Polynomial: ";
    display(poly1);

    cout << "Second Polynomial: ";
    display(poly2);

    Node* sum = addPoly(poly1, poly2);

    cout << "\nSum of Polynomials: ";
    display(sum);

    return 0;
}