#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node * createnode(){
    node *newnode = new node();
    newnode->next = NULL;
    return newnode;
}

node * createlist(){
    node *head = createnode();
    node *temp = head;
    int ch;
    while(1){
        cout<<"enter 1 if want to insert value or 0";
        cin >>ch;

        if(ch == 0){
            break;
        }
        node*newnode=createnode();
        cout <<"Enter data";
        cin>>newnode->data;
        temp->next = newnode;
        newnode->next = head->next;
        temp = newnode;
    }
    return head;
}

void disp(node*&head){
    if (head == NULL){
        cout<<"List is empty";
    }
    node*temp=head->next;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp != head->next);
}

void insertbig(node*&head){
    node*newnode = createnode();
    cout<<"Enter data:";
    cin>>newnode->data;
    node*temp=head->next;
    if(head->next==NULL){
        head->next= newnode;
        newnode->next=newnode;
    }else{
        while(temp->next != head->next){
            temp=temp->next;
        }

        temp->next = newnode;
        newnode->next = head->next;
        head->next = newnode;
    }
}

void insertend(node*&head){
    if(head->next==NULL){
        cout<<"Empty";
        return;
    }

    node*temp = head->next;
    while(temp->next != head->next){
        temp = temp->next;
    }

    node*newnode = createnode();
    cout<<"Enter data";
    cin>>newnode->data;

    temp->next = newnode;
    newnode->next = head->next;
}

void delbeg(node*head){
    node*temp = head->next;
    while(temp->next != head->next){
        temp= temp->next;
    }

    node*freenode=head->next;
    temp->next = freenode->next;
    head->next = freenode->next;

    delete freenode;
}

int main(){
    node* head = createlist();
    disp(head);

    insertbig(head);
    disp(head);

    insertend(head);
    disp(head);

    delbeg(head);
    disp(head);
    return 0;
}