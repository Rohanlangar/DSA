#include<iostream>
#include<string>
using namespace std;

typedef struct student {
    unsigned int roll_no ;
    float marks ; 
    string name;
    struct student * next;
}student;

student * getnode()
{
    student *newnode = new student;
    if(newnode == NULL)
    {
        cout << "getnode():Memory not allocated!!!";
        exit(-1);
    }
    return newnode;
}

student *createNode (){
    student * head = getnode();
    head->next = NULL;
    student *temp = head;
    while(1){
        int ch;
        string names;
        cout << "Do you want to insert the value, if yes type 1 otherwise 0 :";
        cin >> ch;
        if (ch == 0){
            break;
        }
        student *cur = getnode();
        cout <<"Enter roll no :";
        cin >> cur->roll_no;
        cout << "Enter marks :";
        cin >> cur->marks;
        cout << "Enter Name :";
        cin >> names;
        cur->name = names;
        cur->next = NULL;
        temp->next = cur;
        temp = temp->next;
    }
    return head;
}

void printList(student *head){
    student *temp = head->next;
    cout << "Head ->";
    while (temp != NULL){
        cout << "Roll No :" << temp->roll_no << " " << "Marks :" << temp->marks << " " << "Name :" << temp->name << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout <<endl;
    cout <<endl;
}

void del(student *&head){
    student *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

void push_front(student *head) {
    string name;
    student *newnode = getnode();
    cout <<"Enter details :"<<endl; 
    cout << "Roll number :";
    cin >> newnode->roll_no;
    cout<<"Enter marks :";
    cin >> newnode->marks;
    cout <<"Enter Name :";
    cin >>name;
    newnode->name = name;
    newnode->next = head->next;
    head->next = newnode;
}

void push_back(student *head) {
    string name;
    student *node = getnode();
    cout <<"Enter details :"<<endl; 
    cout << "Roll number :";
    cin >> node->roll_no;
    cout<<"Enter marks :";
    cin >> node->marks;
    cout <<"Enter Name :";
    cin >>name;
    node->next = NULL;
    student *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
}

void pop_front(student *head) {
    if (head->next == NULL) return;
    student *temp = head->next;
    head->next = temp->next;
    delete temp;
}

void pop_back(student *head) {
    if (head->next == NULL) return;
    student *prev = head, *cur = head->next;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    delete cur;
}

void insert_after(student *head) {
    student *temp = head->next;
    int roll_no;
    cout<<"Enter roll number after you want to insert data :";
    cin >> roll_no;
    while (temp != NULL && temp->roll_no != roll_no){
        temp = temp->next;
    }
    if (temp == NULL){
        cout << "Value " << roll_no << " not found!" << endl;
        return;
    }
    string name;
    student *newnode = getnode();
    cout << "Enter value to insert after " << roll_no << ": "<<endl;
    cout << "Roll number :";
    cin >> newnode->roll_no;
    cout<<"Enter marks :";
    cin >> newnode->marks;
    cout <<"Enter Name :";
    cin >>name;
    newnode->name = name;

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_value(student *head) {
    student *prev = head, *cur = head->next;
    int roll_no;
    cout <<"Enter roll number you want to delete :";
    cin >>roll_no;
    while (cur != NULL && cur->roll_no != roll_no) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        cout << "Node with roll_no " << roll_no << " not found." << endl;
        return;
    }
    prev->next = cur->next;
    delete cur;
}

int main(){
    cout << "****** Singly Linked List ******" << endl;
    student *head = createNode();
    printList(head);

    cout <<"***** Perfom operations on singly linked list *****"<<endl;
    int ch;
    do{
        cout <<"1) Push front\n 2)Pop front \n 3)Push back \n 4)pop back \n 5)Insert after a roll number \n 6) Delete perticular node \n 7)delete entire linkedlist \n 8)Print List \n 0)Exit"<<endl;
        cin >> ch;

        switch (ch)
        {
        case  1:
            push_front(head);
            cout <<"Data pushed successfully";
            break;
        case 2:
            pop_front(head);
            cout <<"Data poped successfully";
            break;
        case 3: 
                push_back(head);
                cout <<"data pushed successfully";
                break;

        case 4 :
            pop_back(head);
            cout <<"data poped successfully";
            break;

        case 5:
            insert_after(head);
            cout <<"data inserted after specific node successfully";
            break;

        case 6:
            delete_value(head);
            cout <<"data deleted successfully";
            break;

        case 7:
            del(head);
            cout <<"Linked list deleted";
            break;

        case 8:
            printList(head);
            break;
        default:
            break;
        }
    }while(ch!=0);

    
    return 0;
}
