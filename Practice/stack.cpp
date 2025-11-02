#include<iostream>
using namespace std;


struct stack{
    int data;
    stack*next;
};

stack* topStack = NULL;


void push(){
    stack *newnode = new stack();
    cout<<"Enter data:";
    cin>>newnode->data;

    newnode->next = topStack;
    topStack = newnode;
}

void pop(){
    if(topStack == NULL){
        cout<<"underflow";
        return;
    }

    stack*temp = topStack;
    topStack=topStack->next;
    delete temp;
}

void disp(){
    cout<<topStack->data;
}

int main(){
    push();
    disp();
    push();
    disp();
    push();
    disp();
    pop();
    disp();
    return 0;
}

