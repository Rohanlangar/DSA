#include<iostream>
#include<string>
using namespace std;

typedef struct member_rrl {
    unsigned int prn_rrl;
    string name_rrl;
    struct member_rrl *next_rrl;
} member_rrl;

member_rrl * getnode_rrl() {
    member_rrl *newnode_rrl = new member_rrl;
    if (newnode_rrl == NULL) {
        cout << "getnode_rrl(): Memory not allocated!" << endl;
        exit(-1);
    }
    newnode_rrl->next_rrl = NULL;
    return newnode_rrl;
}

member_rrl *createList_rrl() {
    member_rrl *head_rrl = getnode_rrl();
    head_rrl->next_rrl = NULL;
    member_rrl *temp_rrl = head_rrl;

    while (1) {
        int ch_rrl;
        cout << "Do you want to add a member? (1 for yes / 0 for no): ";
        cin >> ch_rrl;
        if (ch_rrl == 0)
            break;

        member_rrl *cur_rrl = getnode_rrl();
        cout << "Enter PRN: ";
        cin >> cur_rrl->prn_rrl;
        cout << "Enter Name: ";
        cin >> cur_rrl->name_rrl;
        cur_rrl->next_rrl = NULL;

        temp_rrl->next_rrl = cur_rrl;
        temp_rrl = cur_rrl;
    }
    return head_rrl;
}

void display_rrl(member_rrl *head_rrl) {
    member_rrl *temp_rrl = head_rrl->next_rrl;
    cout << "Head -> ";
    while (temp_rrl != NULL) {
        cout << "[" << temp_rrl->prn_rrl << ", " << temp_rrl->name_rrl << "] -> ";
        temp_rrl = temp_rrl->next_rrl;
    }
    cout << "NULL" << endl << endl;
}

void addPresident_rrl(member_rrl *head_rrl) {
    member_rrl *newnode_rrl = getnode_rrl();
    cout << "Enter President details:" << endl;
    cout << "PRN: ";
    cin >> newnode_rrl->prn_rrl;
    cout << "Name: ";
    cin >> newnode_rrl->name_rrl;
    newnode_rrl->next_rrl = head_rrl->next_rrl;
    head_rrl->next_rrl = newnode_rrl;
}

void addSecretary_rrl(member_rrl *head_rrl) {
    member_rrl *newnode_rrl = getnode_rrl();
    cout << "Enter Secretary details:" << endl;
    cout << "PRN: ";
    cin >> newnode_rrl->prn_rrl;
    cout << "Name: ";
    cin >> newnode_rrl->name_rrl;
    newnode_rrl->next_rrl = NULL;

    member_rrl *temp_rrl = head_rrl;
    while (temp_rrl->next_rrl != NULL)
        temp_rrl = temp_rrl->next_rrl;
    temp_rrl->next_rrl = newnode_rrl;
}

void deletePresident_rrl(member_rrl *head_rrl) {
    if (head_rrl->next_rrl == NULL) {
        cout << "List empty!" << endl;
        return;
    }
    member_rrl *temp_rrl = head_rrl->next_rrl;
    head_rrl->next_rrl = temp_rrl->next_rrl;
    delete temp_rrl;
    cout << "President deleted successfully!" << endl;
}

void deleteSecretary_rrl(member_rrl *head_rrl) {
    if (head_rrl->next_rrl == NULL) {
        cout << "List empty!" << endl;
        return;
    }
    member_rrl *prev_rrl = head_rrl, *cur_rrl = head_rrl->next_rrl;
    while (cur_rrl->next_rrl != NULL) {
        prev_rrl = cur_rrl;
        cur_rrl = cur_rrl->next_rrl;
    }
    prev_rrl->next_rrl = NULL;
    delete cur_rrl;
    cout << "Secretary deleted successfully!" << endl;
}

void countMembers_rrl(member_rrl *head_rrl) {
    int count_rrl = 0;
    member_rrl *temp_rrl = head_rrl->next_rrl;
    while (temp_rrl != NULL) {
        count_rrl++;
        temp_rrl = temp_rrl->next_rrl;
    }
    cout << "Total Members: " << count_rrl << endl;
}

void search_rrl(member_rrl *head_rrl) {
    unsigned int prn_rrl;
    cout << "Enter PRN to search: ";
    cin >> prn_rrl;
    member_rrl *temp_rrl = head_rrl->next_rrl;
    while (temp_rrl != NULL) {
        if (temp_rrl->prn_rrl == prn_rrl) {
            cout << "Member found: " << temp_rrl->name_rrl << endl;
            return;
        }
        temp_rrl = temp_rrl->next_rrl;
    }
    cout << "Member not found!" << endl;
}

void sort_rrl(member_rrl *head_rrl) {
    if (head_rrl->next_rrl == NULL) return;
    int swapped_rrl;
    member_rrl *ptr1_rrl;
    member_rrl *lptr_rrl = NULL;

    do {
        swapped_rrl = 0;
        ptr1_rrl = head_rrl->next_rrl;

        while (ptr1_rrl->next_rrl != lptr_rrl) {
            if (ptr1_rrl->prn_rrl > ptr1_rrl->next_rrl->prn_rrl) {
                swap(ptr1_rrl->prn_rrl, ptr1_rrl->next_rrl->prn_rrl);
                swap(ptr1_rrl->name_rrl, ptr1_rrl->next_rrl->name_rrl);
                swapped_rrl = 1;
            }
            ptr1_rrl = ptr1_rrl->next_rrl;
        }
        lptr_rrl = ptr1_rrl;
    } while (swapped_rrl);

    cout << "List sorted by PRN successfully!" << endl;
}

void reverse_rrl(member_rrl *head_rrl) {
    member_rrl *prev_rrl = NULL, *cur_rrl = head_rrl->next_rrl, *next_rrl = NULL;
    while (cur_rrl != NULL) {
        next_rrl = cur_rrl->next_rrl;
        cur_rrl->next_rrl = prev_rrl;
        prev_rrl = cur_rrl;
        cur_rrl = next_rrl;
    }
    head_rrl->next_rrl = prev_rrl;
    cout << "List reversed successfully!" << endl;
}

member_rrl *concatenate_rrl(member_rrl *head1_rrl, member_rrl *head2_rrl) {
    member_rrl *temp_rrl = head1_rrl;
    while (temp_rrl->next_rrl != NULL)
        temp_rrl = temp_rrl->next_rrl;
    temp_rrl->next_rrl = head2_rrl->next_rrl;
    return head1_rrl;
}

void deleteList_rrl(member_rrl *&head_rrl) {
    member_rrl *temp_rrl;
    while (head_rrl != NULL) {
        temp_rrl = head_rrl;
        head_rrl = head_rrl->next_rrl;
        delete temp_rrl;
    }
}

int main() {
    cout << "******* Vertex Club Membership Management *******" << endl;
    member_rrl *divisionA_rrl = NULL, *divisionB_rrl = NULL, *merged_rrl = NULL;
    divisionA_rrl = createList_rrl();

    int choice_rrl;
    do {
        cout << "\n---- MENU ----" << endl;
        cout << "1) Display Members\n2) Add President\n3) Add Secretary\n4) Delete President\n5) Delete Secretary\n6) Count Members\n7) Search by PRN\n8) Sort by PRN\n9) Reverse List\n10) Concatenate Two Lists\n0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rrl;

        switch (choice_rrl) {
        case 1:
            display_rrl(divisionA_rrl);
            break;
        case 2:
            addPresident_rrl(divisionA_rrl);
            break;
        case 3:
            addSecretary_rrl(divisionA_rrl);
            break;
        case 4:
            deletePresident_rrl(divisionA_rrl);
            break;
        case 5:
            deleteSecretary_rrl(divisionA_rrl);
            break;
        case 6:
            countMembers_rrl(divisionA_rrl);
            break;
        case 7:
            search_rrl(divisionA_rrl);
            break;
        case 8:
            sort_rrl(divisionA_rrl);
            break;
        case 9:
            reverse_rrl(divisionA_rrl);
            break;
        case 10:
            cout << "Creating Division B list..." << endl;
            divisionB_rrl = createList_rrl();
            merged_rrl = concatenate_rrl(divisionA_rrl, divisionB_rrl);
            cout << "Lists concatenated successfully!" << endl;
            display_rrl(merged_rrl);
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice_rrl != 0);

    deleteList_rrl(divisionA_rrl);
    deleteList_rrl(divisionB_rrl);

    return 0;
}
