#include <iostream>
#include <string>
using namespace std;

struct Node_rrl {
    int empid_rrl;
    string name_rrl;
    Node_rrl *left_rrl, *right_rrl;
};

Node_rrl* createNode_rrl(int empid_rrl, string name_rrl) {
    Node_rrl* newNode_rrl = new Node_rrl;
    newNode_rrl->empid_rrl = empid_rrl;
    newNode_rrl->name_rrl = name_rrl;
    newNode_rrl->left_rrl = newNode_rrl->right_rrl = NULL;
    return newNode_rrl;
}

Node_rrl* insert_rrl(Node_rrl* root_rrl, int empid_rrl, string name_rrl) {
    if (root_rrl == NULL)
        return createNode_rrl(empid_rrl, name_rrl);
    if (empid_rrl < root_rrl->empid_rrl)
        root_rrl->left_rrl = insert_rrl(root_rrl->left_rrl, empid_rrl, name_rrl);
    else if (empid_rrl > root_rrl->empid_rrl)
        root_rrl->right_rrl = insert_rrl(root_rrl->right_rrl, empid_rrl, name_rrl);
    return root_rrl;
}

Node_rrl* search_rrl(Node_rrl* root_rrl, int empid_rrl) {
    if (root_rrl == NULL || root_rrl->empid_rrl == empid_rrl)
        return root_rrl;
    if (empid_rrl < root_rrl->empid_rrl)
        return search_rrl(root_rrl->left_rrl, empid_rrl);
    return search_rrl(root_rrl->right_rrl, empid_rrl);
}

void inorder_rrl(Node_rrl* root_rrl) {
    if (root_rrl != NULL) {
        inorder_rrl(root_rrl->left_rrl);
        cout << root_rrl->empid_rrl << " - " << root_rrl->name_rrl << endl;
        inorder_rrl(root_rrl->right_rrl);
    }
}

int main() {
    Node_rrl* root_rrl = NULL;
    int choice_rrl, empid_rrl;
    string name_rrl;

    while (true) {
        cout << "\n1. Insert Employee\n2. Search Employee\n3. Display Sorted Data\n4. Exit\nEnter choice: ";
        cin >> choice_rrl;
        if (choice_rrl == 1) {
            cout << "Enter Employee ID: ";
            cin >> empid_rrl;
            cout << "Enter Employee Name: ";
            cin >> name_rrl;
            root_rrl = insert_rrl(root_rrl, empid_rrl, name_rrl);
        } else if (choice_rrl == 2) {
            cout << "Enter Employee ID to search: ";
            cin >> empid_rrl;
            Node_rrl* result_rrl = search_rrl(root_rrl, empid_rrl);
            if (result_rrl)
                cout << "Record Found: " << result_rrl->empid_rrl << " - " << result_rrl->name_rrl << endl;
            else
                cout << "Record Not Found.\n";
        } else if (choice_rrl == 3) {
            cout << "Employees Sorted by emp_id:\n";
            inorder_rrl(root_rrl);
        } else if (choice_rrl == 4)
            break;
        else
            cout << "Invalid choice.\n";
    }
    return 0;
}
