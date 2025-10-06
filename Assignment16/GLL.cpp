#include <iostream>
#include <string>
#include <new>
using namespace std;

typedef struct node_rrl {
    int flag_rrl;                // 0 = atom/data, 1 = sublist
    string data_rrl;             // valid if flag == 0
    struct node_rrl *down_rrl;   // valid if flag == 1
    struct node_rrl *next_rrl;   // next element at same level
} node_rrl;

// Function to create a new node
node_rrl* getNode_rrl(int flag_rrl, string data_rrl = "") {
    node_rrl* newnode_rrl = new(nothrow) node_rrl;
    if (!newnode_rrl) {
        cout << "Memory allocation failed!\n";
        exit(-1);
    }
    newnode_rrl->flag_rrl = flag_rrl;
    newnode_rrl->data_rrl = data_rrl;
    newnode_rrl->down_rrl = NULL;
    newnode_rrl->next_rrl = NULL;
    return newnode_rrl;
}

// Function to insert a data node (atom)
void insertData_rrl(node_rrl* &head_rrl, string value_rrl) {
    node_rrl* newnode_rrl = getNode_rrl(0, value_rrl);
    if (!head_rrl) {
        head_rrl = newnode_rrl;
    } else {
        node_rrl* temp_rrl = head_rrl;
        while (temp_rrl->next_rrl)
            temp_rrl = temp_rrl->next_rrl;
        temp_rrl->next_rrl = newnode_rrl;
    }
    cout << "Inserted element: " << value_rrl << endl;
}

// Function to insert a sublist
void insertSublist_rrl(node_rrl* &head_rrl) {
    cout << "Creating sublist...\n";
    node_rrl* sublist_rrl = NULL;
    int n_rrl;
    cout << "Enter number of elements in sublist: ";
    cin >> n_rrl;

    for (int i_rrl = 0; i_rrl < n_rrl; i_rrl++) {
        string val_rrl;
        cout << "Enter element " << i_rrl + 1 << ": ";
        cin >> val_rrl;
        insertData_rrl(sublist_rrl, val_rrl);
    }

    node_rrl* newnode_rrl = getNode_rrl(1);
    newnode_rrl->down_rrl = sublist_rrl;

    if (!head_rrl)
        head_rrl = newnode_rrl;
    else {
        node_rrl* temp_rrl = head_rrl;
        while (temp_rrl->next_rrl)
            temp_rrl = temp_rrl->next_rrl;
        temp_rrl->next_rrl = newnode_rrl;
    }
    cout << "Sublist inserted successfully!\n";
}

// Recursive function to display the GLL
void display_rrl(node_rrl* head_rrl) {
    cout << "{ ";
    node_rrl* temp_rrl = head_rrl;
    while (temp_rrl) {
        if (temp_rrl->flag_rrl == 0)
            cout << temp_rrl->data_rrl;
        else
            display_rrl(temp_rrl->down_rrl);

        if (temp_rrl->next_rrl)
            cout << ", ";
        temp_rrl = temp_rrl->next_rrl;
    }
    cout << " }";
}

// Recursive function to search an element in the GLL
bool search_rrl(node_rrl* head_rrl, const string &target_rrl) {
    node_rrl* temp_rrl = head_rrl;
    while (temp_rrl) {
        if (temp_rrl->flag_rrl == 0 && temp_rrl->data_rrl == target_rrl)
            return true;
        else if (temp_rrl->flag_rrl == 1 && search_rrl(temp_rrl->down_rrl, target_rrl))
            return true;
        temp_rrl = temp_rrl->next_rrl;
    }
    return false;
}

// Free memory
void deleteGLL_rrl(node_rrl* &head_rrl) {
    while (head_rrl) {
        if (head_rrl->flag_rrl == 1)
            deleteGLL_rrl(head_rrl->down_rrl);
        node_rrl* temp_rrl = head_rrl;
        head_rrl = head_rrl->next_rrl;
        delete temp_rrl;
    }
}

int main() {
    node_rrl* head_rrl = NULL;
    int choice_rrl;

    do {
        cout << "\n====== Generalized Linked List Operations ======\n";
        cout << "1) Insert Element (Atom)\n";
        cout << "2) Insert Sublist\n";
        cout << "3) Display Set\n";
        cout << "4) Search Element\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rrl;

        switch (choice_rrl) {
            case 1: {
                string val_rrl;
                cout << "Enter element to insert: ";
                cin >> val_rrl;
                insertData_rrl(head_rrl, val_rrl);
                break;
            }
            case 2:
                insertSublist_rrl(head_rrl);
                break;
            case 3:
                cout << "\nGLL Representation:\n";
                display_rrl(head_rrl);
                cout << "\n";
                break;
            case 4: {
                string target_rrl;
                cout << "Enter element to search: ";
                cin >> target_rrl;
                if (search_rrl(head_rrl, target_rrl))
                    cout << target_rrl << " found in GLL.\n";
                else
                    cout << target_rrl << " not found.\n";
                break;
            }
            case 0:
                cout << "Exiting program...\n";
                deleteGLL_rrl(head_rrl);
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice_rrl != 0);

    return 0;
}
