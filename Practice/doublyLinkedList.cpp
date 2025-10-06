#include<iostream>
using namespace std;

struct dll {
    int val ;
    dll *next ;
    dll *pre;
};

dll * createnode(){
    dll *newnode = new dll();
    newnode->next = NULL;
    newnode->pre = NULL;
    return newnode;
}

dll * createNewList(){
    dll * head = createnode();   
    dll*temp = head;
    int ch;
    while (1){
        cout << "Enter 1 to continue and 0 to exit : ";
        cin >> ch;

        if (ch == 0){
            break;
        }
        dll *newnode = createnode();
        cout << "Enter value for linked list: ";
        cin >> newnode->val;
        newnode->pre = temp;
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
}

void print(dll *head){
    dll *temp = head->next; 
    while (temp != NULL){
        cout << temp->val << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void push_front(dll *&head){
    dll *temp = head;
    dll *newnode = createnode();
    cout <<"Enter value for new node (front): ";
    cin >> newnode->val;

    newnode->next = temp->next;
    newnode->pre = temp;
    if (temp->next != NULL) temp->next->pre = newnode;
    temp->next = newnode;
}

void push_back(dll *&head){
    dll *temp = head;

    while (temp->next != NULL){
        temp = temp->next;
    }

    dll * newnode= createnode();
    cout << "Enter value for last node: ";
    cin >> newnode->val;

    temp->next = newnode;
    newnode->pre= temp;
}

void pop_front(dll *&head){
    if (head->next == NULL){
        cout << "List is empty!" << endl;
        return;
    }
    dll *todelete = head->next;
    head->next = todelete->next;
    if (todelete->next != NULL){
        todelete->next->pre = head;
    }
    cout << "Deleted (front): " << todelete->val << endl;
    delete todelete;
}

void pop_back(dll *&head){
    if (head->next == NULL){
        cout << "List is empty!" << endl;
        return;
    }
    dll *temp = head->next;
    while (temp->next != NULL){
        temp = temp->next;
    }
    cout << "Deleted (back): " << temp->val << endl;
    temp->pre->next = NULL;
    delete temp;
}

void insert_after(dll *&head, int key){
    dll *temp = head->next;
    while (temp != NULL && temp->val != key){
        temp = temp->next;
    }
    if (temp == NULL){
        cout << "Value " << key << " not found!" << endl;
        return;
    }
    dll *newnode = createnode();
    cout << "Enter value to insert after " << key << ": ";
    cin >> newnode->val;

    newnode->next = temp->next;
    newnode->pre = temp;
    if (temp->next != NULL) temp->next->pre = newnode;
    temp->next = newnode;
}

void delete_value(dll *&head, int key){
    dll *temp = head->next;
    while (temp != NULL && temp->val != key){
        temp = temp->next;
    }
    if (temp == NULL){
        cout << "Value " << key << " not found!" << endl;
        return;
    }
    temp->pre->next = temp->next;
    if (temp->next != NULL){
        temp->next->pre = temp->pre;
    }
    cout << "Deleted value: " << temp->val << endl;
    delete temp;
}

int main(){
    dll*head = createNewList();
    cout << "Initial List: ";
    print(head);

    push_front(head);
    print(head);

    push_back(head);
    print(head);

    pop_front(head);
    print(head);

    pop_back(head);
    print(head);

    insert_after(head, 2);   
    print(head);

    delete_value(head, 3);   
    print(head);

    return 0;
}
