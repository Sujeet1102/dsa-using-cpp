// Queue implementation using Linked List
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(rear == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void Dequeue(){
    Node* temp = front;
    if(front  == NULL){
        cout << "Empty Queue";
        return;
    }
    else if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    // cout << temp->data;
    delete (temp);
}
void Display(){
    Node* temp = front;
    cout << "Queue is: ";
    while(temp !=NULL){
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << "\n";
}
int main(){
    Enqueue(2);
    Enqueue(4);
    Enqueue(6);
    Display();
    Dequeue();
    Display();
    Dequeue();
    Display();
}