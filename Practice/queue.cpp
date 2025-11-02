#include<iostream>
using namespace std;
int queue[100];
int front=-1,rear=-1;

void enqueue(int val){
    if(rear == 100-1){
        cout<<"Overflow";
        return;
    }

    if(front == -1)front = 0;
    queue[++rear]=val;
}

void dequeue(){
if(front == -1 || front >rear){
        cout<<"Underflow";
        return;
    }

    front++;
}

void disp(){
    if(front == -1 || front >rear){
        cout<<"Underflow";
        return;
    }

    for(int i = front ; i<=rear ;i++){
        cout<<queue[i];
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    disp();
    dequeue();
    disp();

    return 0;
}