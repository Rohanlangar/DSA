#include <iostream>
using namespace std;

struct PolyNode {
    int coeff;
    int exp;
    PolyNode* next;
};

PolyNode* createNode_rrl(int coeff, int exp) {
    PolyNode* node = new PolyNode;
    node->coeff = coeff;
    node->exp = exp;
    node->next = nullptr;
    return node;
}

PolyNode* createPoly_rrl() {
    int n, coeff, exp;
    cout << "Enter number of terms in polynomial: ";
    cin >> n;

    PolyNode* head = nullptr;
    PolyNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient for term " << i+1 << ": ";
        cin >> coeff;
        cout << "Enter exponent for term " << i+1 << ": ";
        cin >> exp;

        PolyNode* node = createNode_rrl(coeff, exp);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void displayPoly_rrl(PolyNode* head) {
    if (!head) {
        cout << "0\n";
        return;
    }
    PolyNode* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->exp;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

PolyNode* addPoly_rrl(PolyNode* p1, PolyNode* p2) {
    PolyNode* result = nullptr;
    PolyNode* tail = nullptr;

    while (p1 && p2) {
        PolyNode* node = nullptr;
        if (p1->exp > p2->exp) {
            node = createNode_rrl(p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            node = createNode_rrl(p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                node = createNode_rrl(sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }

        if (node) {
            if (!result) result = tail = node;
            else { tail->next = node; tail = node; }
        }
    }

    while (p1) {
        PolyNode* node = createNode_rrl(p1->coeff, p1->exp);
        if (!result) result = tail = node;
        else { tail->next = node; tail = node; }
        p1 = p1->next;
    }
    while (p2) {
        PolyNode* node = createNode_rrl(p2->coeff, p2->exp);
        if (!result) result = tail = node;
        else { tail->next = node; tail = node; }
        p2 = p2->next;
    }

    return result;
}

int main() {
    cout << "Create first polynomial:\n";
    PolyNode* poly1 = createPoly_rrl();
    cout << "Create second polynomial:\n";
    PolyNode* poly2 = createPoly_rrl();

    cout << "\nFirst Polynomial: ";
    displayPoly_rrl(poly1);
    cout << "Second Polynomial: ";
    displayPoly_rrl(poly2);

    PolyNode* sum = addPoly_rrl(poly1, poly2);
    cout << "\nSum of Polynomials: ";
    displayPoly_rrl(sum);

    return 0;
}
