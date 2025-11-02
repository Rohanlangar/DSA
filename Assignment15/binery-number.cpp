#include <iostream>
using namespace std;

struct Node_rrl {
    int data_rrl;
    Node_rrl* prev_rrl;
    Node_rrl* next_rrl;
    Node_rrl(int val_rrl) {
        data_rrl = val_rrl;
        prev_rrl = next_rrl = nullptr;
    }
};

class BinaryNumber_rrl {
public:
    Node_rrl* head_rrl;
    Node_rrl* tail_rrl;

    BinaryNumber_rrl() {
        head_rrl = tail_rrl = nullptr;
    }

    void insertBit_rrl(int bit_rrl) {
        Node_rrl* newNode_rrl = new Node_rrl(bit_rrl);
        if (!head_rrl) {
            head_rrl = tail_rrl = newNode_rrl;
        } else {
            tail_rrl->next_rrl = newNode_rrl;
            newNode_rrl->prev_rrl = tail_rrl;
            tail_rrl = newNode_rrl;
        }
    }

    void display_rrl() {
        Node_rrl* temp_rrl = head_rrl;
        while (temp_rrl) {
            cout << temp_rrl->data_rrl;
            temp_rrl = temp_rrl->next_rrl;
        }
        cout << endl;
    }

    BinaryNumber_rrl onesComplement_rrl() {
        BinaryNumber_rrl result_rrl;
        Node_rrl* temp_rrl = head_rrl;
        while (temp_rrl) {
            result_rrl.insertBit_rrl(temp_rrl->data_rrl == 0 ? 1 : 0);
            temp_rrl = temp_rrl->next_rrl;
        }
        return result_rrl;
    }

    BinaryNumber_rrl twosComplement_rrl() {
        BinaryNumber_rrl oneComp_rrl = onesComplement_rrl();

        Node_rrl* temp_rrl = oneComp_rrl.tail_rrl;
        int carry_rrl = 1;

        while (temp_rrl && carry_rrl) {
            int sum_rrl = temp_rrl->data_rrl + carry_rrl;
            temp_rrl->data_rrl = sum_rrl % 2;
            carry_rrl = sum_rrl / 2;
            temp_rrl = temp_rrl->prev_rrl;
        }

        if (carry_rrl) {
            Node_rrl* newNode_rrl = new Node_rrl(1);
            newNode_rrl->next_rrl = oneComp_rrl.head_rrl;
            oneComp_rrl.head_rrl->prev_rrl = newNode_rrl;
            oneComp_rrl.head_rrl = newNode_rrl;
        }

        return oneComp_rrl;
    }

    static BinaryNumber_rrl add_rrl(BinaryNumber_rrl& A_rrl, BinaryNumber_rrl& B_rrl) {
        BinaryNumber_rrl result_rrl;
        Node_rrl* p_rrl = A_rrl.tail_rrl;
        Node_rrl* q_rrl = B_rrl.tail_rrl;
        int carry_rrl = 0;

        while (p_rrl != nullptr || q_rrl != nullptr || carry_rrl != 0) {
            int bit1_rrl = (p_rrl) ? p_rrl->data_rrl : 0;
            int bit2_rrl = (q_rrl) ? q_rrl->data_rrl : 0;
            int sum_rrl = bit1_rrl + bit2_rrl + carry_rrl;

            result_rrl.insertAtFront_rrl(sum_rrl % 2);
            carry_rrl = sum_rrl / 2;

            if (p_rrl) p_rrl = p_rrl->prev_rrl;
            if (q_rrl) q_rrl = q_rrl->prev_rrl;
        }

        return result_rrl;
    }

    void insertAtFront_rrl(int bit_rrl) {
        Node_rrl* newNode_rrl = new Node_rrl(bit_rrl);
        if (!head_rrl) {
            head_rrl = tail_rrl = newNode_rrl;
        } else {
            newNode_rrl->next_rrl = head_rrl;
            head_rrl->prev_rrl = newNode_rrl;
            head_rrl = newNode_rrl;
        }
    }
};

int main() {
    BinaryNumber_rrl num1_rrl, num2_rrl;

    cout << "Enter first binary number: ";
    string s1_rrl;
    cin >> s1_rrl;
    for (char c_rrl : s1_rrl)
        num1_rrl.insertBit_rrl(c_rrl - '0');

    cout << "Binary number stored as DLL: ";
    num1_rrl.display_rrl();

    cout << "\n1's Complement: ";
    BinaryNumber_rrl oneComp_rrl = num1_rrl.onesComplement_rrl();
    oneComp_rrl.display_rrl();

    cout << "2's Complement: ";
    BinaryNumber_rrl twoComp_rrl = num1_rrl.twosComplement_rrl();
    twoComp_rrl.display_rrl();

    cout << "\nEnter second binary number to add: ";
    string s2_rrl;
    cin >> s2_rrl;
    for (char c_rrl : s2_rrl)
        num2_rrl.insertBit_rrl(c_rrl - '0');

    cout << "First Number: ";
    num1_rrl.display_rrl();
    cout << "Second Number: ";
    num2_rrl.display_rrl();

    BinaryNumber_rrl sum_rrl = BinaryNumber_rrl::add_rrl(num1_rrl, num2_rrl);
    cout << "Sum: ";
    sum_rrl.display_rrl();

    return 0;
}